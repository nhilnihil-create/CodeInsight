#include<bits/stdc++.h>
using namespace std;

#define ll long long
//~ #define endl '\n'

void solve(){
	int n, ans = 0; cin>>n;
	unordered_map< string, int > m, vis;
	vector< string > s(n), v;
	for(int i = 0; i<n; i++){
		cin>>s[i];
		m[s[i]]++;
		ans = max(m[s[i]], ans);
	}
	for(int i = 0; i<n; i++){
		if(m[s[i]] == ans && vis[s[i]] == 0){
			v.push_back(s[i]);
			vis[s[i]]++;
		}
	}
	sort(v.begin(), v.end());
	for(string i : v) cout<<i<<endl;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t = 1;// cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
