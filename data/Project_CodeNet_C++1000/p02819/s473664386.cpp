#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
bitset<MAXN> mark;
vector<int> primes;

void crivo(void){
	mark.set();
	mark[0] = mark[1] = 0;
	for (int i = 2; i <= MAXN; i++){
		if (!mark[i]) continue;
		for (int j = i + i; j <= MAXN; j+=i){
			mark[j] = 0;
		}
		primes.push_back(i);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	crivo();
	int x;
	cin >> x;
	cout << *lower_bound(primes.begin(), primes.end(), x) << "\n"; 
	return 0;
}