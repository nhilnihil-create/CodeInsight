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
	int n,m;
	cin>>n>>m;
	vector<int>a[n+1];
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		a[x].pb(y);
		a[y].pb(x);
	}
	queue<int>q;
	int lev[n+1]={0};
	q.push(1);
	int vis[n+1]={0};
	vis[1]=1;
	while(!q.empty()){
		int p=q.front();
		q.pop();
		for(auto x:a[p]){
			if(!vis[x]){
				lev[x]=p;
				q.push(x);
				vis[x]=1;
			}
		}
	}
	int f=0;
	for(int i=2;i<=n;i++){
		if(!lev[i])
			f=1;
	}
	if(f)
		cout<<"No\n";
	else
	{
		cout<<"Yes\n";
		for(int i=2;i<=n;i++)cout<<lev[i]<<endl;
	}
			
}
