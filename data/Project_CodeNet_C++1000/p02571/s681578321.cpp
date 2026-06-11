#pragma GCC optimize("Ofast")  
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long 
#define endl "\n"
#define all(x) (x).begin(),(x).end()
const int MOD = 1e9+7;
const int mxN = 2e5+3;

void solve(){
	string s, t;
	cin >> s >> t;
	int slen = (int)s.length();
	int tlen = (int)t.length();
	int ans = tlen;
	for(int i = 0; i <= slen - tlen; ++i){
		int cur = 0;
		for(int j = 0; j < tlen; ++j){
			if(s[i + j] != t[j])cur++;
		}
		ans = min(ans, cur);
	}
	cout << ans << endl;
}

int32_t main(){
	IO;
	
	int nT = 1;
	//cin >> nT;
	for(int i = 1; i <= nT; ++i)
		solve();
	return 0;
}
