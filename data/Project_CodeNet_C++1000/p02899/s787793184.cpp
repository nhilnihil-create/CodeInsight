#include<bits/stdc++.h>
using namespace std;
#define int long long
bool comp(pair<int,int>a,pair<int,int>b){
	return a.first<b.first;
}
void solve(){
	int n;cin>>n;
	vector<pair<int,int>>a(n);int x;
	for(int i=0;i<n;i++) {
		cin>>x;
		a[i]={x,i+1};
	}
	sort(a.begin(),a.end());
	for(int i=0;i<a.size();i++) cout<<a[i].second<<" ";
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
