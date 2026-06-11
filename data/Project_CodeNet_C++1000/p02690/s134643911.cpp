#include "bits/stdc++.h"
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target ("avx,avx2")

using namespace std;

using ll = long long;
#define all(x) begin(x), end(x)


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
	int x; cin >> x;
	for(int i{-200}; i<200; ++i)
		for(int j{-200}; j<i; ++j){
			if(pow(i, 5)-pow(j, 5) == x){
				return cout << i << " " << j << "\n", 0;
			}
		}
}
