#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const ll mod = 1e9+7;
const int N = 2e5+6;
ll pre[N];
ll suf[N];
void solve(){
	int n; 
	cin>>n; 
	string s; 
	cin>>s;
	for(int i=1;i<=n;i++){
		pre[i] = pre[i-1];
		if(s[i-1]=='W'){
			pre[i]++;
		}
	}
	for(int i=n;i>=1;i--){
		suf[i] = suf[i+1];
		if(s[i-1]=='R'){
			suf[i]++;
		}
	}
	ll ans = 1e6;
	for(int i=0;i<=n;i++){
		ans = min(ans,max(pre[i],suf[i+1]));
	}
	cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1; 
//	cin>>t; 
	while(t--){
		solve();
	}
	return 0;
}
