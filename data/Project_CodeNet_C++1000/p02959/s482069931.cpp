#include<bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define ff first
#define ss second
typedef long long ll;

int main(){
	int n;cin>>n;
	vector<int>vec(n+1);
	for(int i=0;i<=n;i++)cin>>vec[i];
	vector<int>he(n);
	for(int i=0;i<n;i++)cin>>he[i];
	ll ans=0;
	for(int i=0;i<n;i++){
		ans+=min(vec[i],he[i]);
		he[i]-=min(vec[i],he[i]);
		ans+=min(he[i],vec[i+1]);
		vec[i+1]-=min(he[i],vec[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}
