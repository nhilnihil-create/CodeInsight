#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define unmap  	unordered_map<int,int>
#define	unset	unordered_set<int>
#define maxpq  	priority_queue<int>
#define minpq  	priority_queue<int, vector<int>, greater<int>>
#define sort(v)  sort(v.begin(),v.end());
#define sortd(v) sort(v.begin(),v.end(),greater<int>());
#define pb 		push_back
#define ll 		long long
#define ff 		first
#define ss 		second//typedef second ss;
#define foton(i,n) for(int i=0;i<n;i++)
#define	faton(i,a,n)	for(int i=a;i<=n;i++)
#define mod 	1000000007
#define endl "\n"
using namespace std;

void solve(){
	int n,m;cin>>n>>m;
	ll k;cin>>k;
	vector<ll> asum(n+1,0),bsum(m+1,0);
	for(int i=0;i<n;i++){
        int t;cin>>t;
        asum[i+1] = t+asum[i];
	}
	for(int i=0;i<m;i++){
        int t;cin>>t;
        bsum[i+1] = t+bsum[i];
	}
	int ans = 0;
	for(int i=0;i<=n;i++){
        ll t = k-asum[i];
        if(t <0 ) break;
        int j = upper_bound(bsum.begin(),bsum.end(),t)-bsum.begin()-1;
        ans = max(ans,i+j);
	}
	cout<<ans<<endl;
}

int main(){
	fastio;
	solve();
	return 0;
}

