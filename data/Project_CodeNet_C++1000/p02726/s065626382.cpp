#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define PI 3.141592653589793238
#define dbg(n) cout<<#n<<' '<<n<<endl;
#define dbg_v(v) cout<<#v<<":";for(int i=0;i<(int)v.size();i++) cout<<" "<<v[i]; cout<<endl;
int power(ll x,ll y){ll res = 1;while(y>0){if(y&1)res = (res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	
	int t=1;
	//cin>>t;
	while(t--){
		int x,n,y;
		cin>>n>>x>>y;
		vector<int>a[n];
		for(int i=0;i<n-1;i++){
			a[i].pb(i+1);
			a[i+1].pb(i);
		}
		a[x-1].pb(y-1);
		a[y-1].pb(x-1);
		int ans[n]={0};
		//int done[n]={0};
		for(int i=0;i<n-1;i++){
			//done[i]=1;
			queue<int>q;
			q.push(i);
			int vis[n]={0};
			int lev[n]={0};
			while(!q.empty()){
				int p=q.front();
				q.pop();
				for(auto x:a[p]){
					if(!vis[x]){
						vis[x]=1;
						q.push(x);
						lev[x]=lev[p]+1;
						if(x>i)
							ans[lev[x]]++;
					}
				}
			}
		}
		for(int i=1;i<n;i++)
			cout<<ans[i]<<" "<<endl;
	}
}
