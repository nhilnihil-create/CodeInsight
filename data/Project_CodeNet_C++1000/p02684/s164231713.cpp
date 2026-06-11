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
	int n,k;
	cin>>n>>k;
	vi a(n);
	rep(i,n){
		int z;cin>>z;z--;
		a[i]=z;
	}

	int now=0;
	int cnt=0;
	vi visit[200200];
	visit[0].pb(0);

	bool f=1;
	rep(i,k){
		now=a[now];
		cnt++;
		visit[now].pb(cnt);

		if(f&&visit[now].size()==2){
			f=0;
			int t=visit[now][1]-visit[now][0];
			i+=(k-cnt)/t*t;
		}
	}
	cout<<now+1<<endl;

	return 0;
}

