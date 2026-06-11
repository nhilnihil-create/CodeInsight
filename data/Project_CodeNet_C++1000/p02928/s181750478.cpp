#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
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
	int n,k;
	cin>>n>>k;
	vi a(n);
	rep(i,n)cin>>a[i];

	vi l(2002,0),g(2002,0);

	rep(i,n){
		l[a[i]+1]++;
		l[2001]--;
		g[a[i]]--;
		g[0]++;
	}
	FOR(i,1,2000){
		l[i]+=l[i-1];
		g[i]+=g[i-1];
	}

	int ans=0;
	rep(i,n){
		int cnt=0;
		rep(j,i){
			if(a[i]<a[j]) cnt++;
		}
		cnt*=k;
		cnt%=MOD;

		ans+=cnt;
		ans%=MOD;
		ans+=((k*(k-1)/2)%MOD) * ((/*g[a[i]]+*/l[a[i]])%MOD);
		ans%=MOD;

	}

	cout<<ans<<endl;
	return 0;
}
