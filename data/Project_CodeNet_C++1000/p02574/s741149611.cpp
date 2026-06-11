#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;

vector<P> prime_factorize(int N){
	vector<P> ans;
	for(int a = 2; a*a <= N; a++){
		if(N % a == 0){
			int ex = 0;
			while(N%a == 0){
				ex++;
				N /= a;
			}
			ans.push_back(P(a, ex));
		}
	}
	if(N != 1) ans.push_back(P(N, 1));
	return ans;
}



int main(){
	int n; scanf("%d", &n);
	vector<int> a(n), data(1e6+1, 0);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		auto vec = prime_factorize(a[i]);
		for(int j = 0; j < vec.size(); j++){
			data[vec[j].first]++;
		}
	}
		bool check = true;
	for(int i = 2; i < data.size(); i++){
		if(data[i] >= 2) check = false;
	}
	if(check){
		cout << "pairwise coprime" << endl;
		return 0;
	}
	int g = a[0];
	for(int i = 1; i < n; i++) g = __gcd(g, a[i]);
	if(g == 1){
		cout << "setwise coprime" << endl;
		return 0;
	}
	cout << "not coprime" << endl;
}