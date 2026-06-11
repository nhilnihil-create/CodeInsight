#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
V<int> v[100005];int n,mod=1e9+7,k;
int dfs(int p,int de,int fa){
	int re=1;
	int s=0;
	for(int i=0;i<v[p].size();i++){
		if(fa!=v[p][i]){
			if(de==1){
				re=re*(k-s-1)%mod*dfs(v[p][i],de+1,p)%mod;
			}else{
				re=re*(k-s-2)%mod*dfs(v[p][i],de+1,p)%mod;
			}
			s++;
		} 
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int x,y;
	cin>>n>>k;
	FOR(i,2,n){
		cin>>x>>y;
		v[x].PB(y);v[y].PB(x);
	}
	cout<<k*dfs(1,1,-1)%mod;
	RE 0;
}


