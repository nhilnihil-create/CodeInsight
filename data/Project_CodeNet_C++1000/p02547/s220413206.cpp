#include "bits/stdc++.h"
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target ("avx,avx2")

using namespace std;

using ll = long long;
#define all(x) begin(x), end(x)

void solve(){

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i{}; i<n-2; ++i){
		int a,b; cin >> a >> b;
		if(a==b){
			cin >> a >> b;
			i++;
			if(a==b){
				cin >> a >> b;
				i++;
				if(a==b){
					cout << "Yes" << "\n";
					return 0;
				}
			}
		}
	}

	cout << "No" << "\n";

}
