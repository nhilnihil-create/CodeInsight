//ITNOA
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
const long long INF=1e9+10,MAX=2e5+1e4,MOD=1e9+7,MAXL=25;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,ll> piii;
void OUT(long double o,int x){
	 cout<<fixed<<setprecision(x)<<o;
	 return;
}
ll a[MAX],d[MAX];
vector<int> v[MAX],k[MAX];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,t=0,p=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		k[x].pb(y);
		v[y].pb(x);
	}
	for(int i=0;i<n;i++){
		if(v[i].size()==0)
			a[t++]=i;
		d[i]=v[i].size();
	}
	while(p<t){
		for(int i:k[a[p]]){
			d[i]--;
			if(d[i]==0)
				a[t++]=i;
		}
		p++;
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\n";
	return 0;
}