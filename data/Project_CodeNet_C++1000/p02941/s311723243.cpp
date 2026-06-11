/*input
5
5 6 5 2 1
9817 1108 6890 4343 8704
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define ALL(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define F first
#define S second
#define REP(i,n) for(int i=0;i<((int)n);i++)
#define eb emplace_back
#define pb push_back
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define EL cout<<'\n'
template<typename T1,typename T2>
ostream& operator<<(ostream& out,pair<T1,T2> P){
	out<<'('<<P.F<<','<<P.S<<')';
	return out;
}
template<typename T>
ostream& operator<<(ostream& out,vector<T> V){
	REP(i,SZ(V)) out<<V[i]<<((i!=SZ(V)-1)?" ":"");
	return out;
}
#define version 20190814
//}}}
const ll maxn=300005;
const ll maxlg=20;
const ll INF64=1e18;
const int INF=0x3f3f3f3f;
const ll MOD=ll(1e9+7);
const ld PI=acos(-1);
const ld eps=1e-9;
//const ll p=880301;
//const ll P=31;

ll mypow(ll a,ll b){
	ll res=1LL;
	while(b){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}

int n;
ll a[maxn],b[maxn];
priority_queue<pll> pq;
bool vis[maxn];
int main(){
	IOS;
	cin>>n;
	REP(i,n) cin>>a[i];
	REP(i,n) cin>>b[i];	

	ll ans=0;

	REP(i,n){
		if(a[i]==b[i]){
			vis[i]=1;
		}
		else if(a[i]<b[i]){
			pq.push(MP(b[i],i));
		}
		else{
			cout<<"-1\n";
			return 0;
		}
	}

	while(SZ(pq)){
		pll cur=pq.top();
		pq.pop();
		ll idx=cur.S;
		ll pre=(idx-1+n)%n;
		ll nxt=(idx+1)%n;

		if(vis[pre]&&vis[nxt]){
			if((b[idx]-a[idx])%(b[pre]+b[nxt])!=0){
				cout<<"-1\n";
				return 0;
			}
			ans+=(b[idx]-a[idx])/(b[pre]+b[nxt]);
			b[idx]=a[idx];
			vis[idx]=1;
		}
		else{
			if(b[idx]<=b[pre]+b[nxt]){
				cout<<"-1\n";
				return 0;
			}
			ans+=b[idx]/(b[pre]+b[nxt]);
			b[idx]%=(b[pre]+b[nxt]);
			if(b[idx]<a[idx]){
				cout<<"-1\n";
				return 0;
			}
			if(b[idx]==a[idx]) vis[idx]=1;
			else pq.push(MP(b[idx],idx));
		}
	}
	cout<<ans<<'\n';
	return 0;
}
