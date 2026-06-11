#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int n;int k;cin>>n>>k;
    vector<int>h(n);
    for(int i=0;i<n;i++) cin>>h[i];
    sort(h.begin(),h.end());
    cout<<n-(lower_bound(h.begin(),h.end(),k)-h.begin());
}
int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);	 
	int T=1;
	// cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
