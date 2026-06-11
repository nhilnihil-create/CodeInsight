#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define endl '\n'

void max_self(int &a, int b){ a = max(a, b);}
void min_self(int &a, int b){ a = min(a, b);}

int n, k; vector< int > v;

bool good(int x){
	int cnt = k;
	for(int i = 0; i<n; i++){
		cnt -= (v[i] - 1) / x;
	}
	return cnt >= 0;
}

void solve(){
	cin>>n>>k;
	v.resize(n);
	for(int &i : v) cin>>i;
	int l = 0; // bad
	int r = 1e9; // good

	while(r > l + 1){
		int mid = (l + r) / 2;
		if(good(mid)){
			r = mid;
		}else{
			l = mid;
		}
	}
	cout<<r<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	for(int i = 1; i<=t; i++){
		solve();
	}
	return 0;
}
