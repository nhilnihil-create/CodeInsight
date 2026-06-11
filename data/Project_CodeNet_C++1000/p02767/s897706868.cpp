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
int ans=1e18;
int n;
vector<int> a(n);
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>n;
	a.resize(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<=100;i++){
		int cur=0;
		for(int j=0;j<n;j++) cur+=(a[j]-i)*(a[j]-i);
		ans=min(ans,cur);
	}
	cout<<ans;
	re 0;
}