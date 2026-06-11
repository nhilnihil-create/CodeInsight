#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define loop(k) rep(author_is_masa,k)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/

signed main(){
	int n,m,x;
	cin>>n>>m>>x;
	vi c(n);
	vector<vi> a(n,vi(m));
	rep(i,n){
		cin>>c[i];
		rep(j,m)cin>>a[i][j];
	}

	int ans=INF;

	rep(bit,1<<n){
		vi rikai(m,0);
		int sum=0;
		rep(i,n)if(bit&(1<<i)){
			sum+=c[i];
			rep(j,m){
				rikai[j]+=a[i][j];
			}
		}
		bool ok=1;
		rep(j,m) if(rikai[j]<x) ok=0;
		if(ok) chmin(ans,sum);
	}
	if(ans<INF) cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}

