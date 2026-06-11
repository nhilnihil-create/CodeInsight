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

signed main(){
	ios_base::sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	int sum=0;
	for(int i=0;i<n;i++) cin>>a[i],sum+=a[i];
	sort(rall(a));
	if(a[m-1]*4*m>=sum) cout<<"Yes";
	else cout<<"No"; 
	re 0;
}