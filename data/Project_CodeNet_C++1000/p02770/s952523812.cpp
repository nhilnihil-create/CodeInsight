/*alurquiza*/
//https://matcomgrader.com/problem/9623/dictionary-search/
//Segment Tree + binary search
#include <bits/stdc++.h>

using namespace::std;

typedef long long LL;
const int MOD = 1e9 + 7;

LL pot(int base,int exp){
	if(exp == 1)
		return base;
	if(exp % 2 == 0){
		LL aux = pot(base,exp / 2);
		return aux * aux % MOD;
	}
	return pot(base,exp - 1) * base % MOD;
}

// long long fact(int ini,int fin){
// 	LL r = 1;
// 	while(ini <= fin)
// 		r = r * ini++ % MOD;
// 	return r;
// }

LL C(int N,int K,std::vector<LL> &F){
	return F[N] * pot(F[K],MOD - 2) % MOD * pot(F[N - K],MOD - 2) % MOD;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	// freopen("milkvisits.in","r",stdin);
	// freopen("milkvisits.out","w",stdout);

	int k,q;
	cin >> k >> q;

	std::vector<int> V(k + 1);
	for(int i = 1;i <= k;i++){
		cin >> V[i];
	}

	while(q--){
		int n,x,m;
		cin >> n >> x >> m;

		std::vector<LL> TA(k + 1);
		int cant_0 = 0;
		for(int i = 1;i <= k;i++){
			cant_0 += (V[i] % m == 0);
			TA[i] = TA[i - 1] + (V[i] % m);
		}

		n--;

		// cerr << cant_0 << '\n';

		int tmp = n / k;
		int rsol = cant_0 * tmp;
		long long sum = 1LL * tmp * TA[k] + (x % m);

		// cerr << rsol << '\n';

		for(int i = 0;i < n % k;i++){
			i++;
			rsol += (V[i] % m == 0);
			sum += (V[i] % m);
			i--;
		}

		rsol += sum / m;

		// cerr << rsol << ' ' << sum << '\n';

		cout << n - rsol << '\n';
	}

	return 0;
}

//g++ -std=c++11 -Wall DS.cpp -o main