#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<ll> mat(n);
	ll rsum = 0;
	for(int i = 0;i < n; ++i){
		cin >> mat[i];
		rsum ^= mat[i];
	}
	for(int i = 0;i < n; ++i){
		mat[i] &= (~rsum);
	}
	ll l = 0; 
	ll ans = 0;
	for(int i = 63;i >= 0; --i){
		for(int j = l; j < n; ++j){
			if((mat[j] >> i) & 1){
				swap(mat[l], mat[j]);
			}
		}
		if(((mat[l] >> i)&1) == 0)continue;
		for(int j = 0;j < n; ++j){
			if(j == l)continue;
			if((mat[j] >> i) & 1){
				mat[j] ^= mat[l];	
			}
		}
		++l;
		if(l >= n)break;
	}
	for(int i = 0;i < n; ++i){
		ans^=mat[i];
	}

	cout << 2 * ans + rsum << '\n';
}
