#include<bits/stdc++.h>
#define int long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
vector<string> ans;
map<string,int> mp;
int n,mx=-1;
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		mp[s]++;
	}
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++) mx=max(mx,it->se);
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
		if(it->se==mx)
			ans.pb(it->fi);
	sort(all(ans));
	for(int i=0;i<sz(ans);i++) cout<<ans[i]<<"\n";	
	re 0;
}