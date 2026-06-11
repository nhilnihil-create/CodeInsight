#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i,n) for(int i=0; i<(n); ++i)
#define FOR(i,a,b) for (int i = a; i < b; i++)
const int mod = 1e9 + 7;


int main(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	int n,m;
	cin >> n >> m;
	ll total = 0;
	std::vector<int> a(n);
	FOR(i,0,n){
		cin >> a[i];
		total+=a[i];
	}
	ll count = 0;
	FOR(i,0,n){
		if(a[i]*m*4 >= total) count++;
	}
	if(count >=m){
		cout << "Yes" << "\n";
	}else{
		cout << "No" << "\n";
	}
	return 0;
}