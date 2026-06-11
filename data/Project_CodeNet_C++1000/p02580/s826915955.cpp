#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define INF (int)1e9+4
#define INFL (ll)1e18+4
#define md (int)1e9+7
#define mx 10000000  //use fixed<<setprecion 
#define mk make_pair
#define pi pair<int,int>
#define ss second
#define ff first
#define pb emplace_back 
#define onell(x) __builtin_popcountll(x)
#define one(x) __builtin_popcount(x)
#define all(s) s.begin(),s.end()
#define rall(x) (x).rbegin(), (x).rend()
#define trav(x, a) for (auto& x: a)
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>b;i--)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define sz(x) ((long long)x.size())
#define mez(s) memset(s,0,sizeof s)
#define mex(s) memset(s,-1,sizeof s)
#define metr(s) memset(s,true, sizeof s)
typedef vector<int> vi; 
typedef vector<ll>vl;
typedef map<int,int> mp;
typedef queue<int> que;
typedef vector<pi> vp;
const int mxn=300300;
int c[mxn],d[mxn];
void solve(){
int n=0,x=0,y=0,z=0,m=0,k=0;
cin>>n>>m>>k;mez(c);
set<pi>s;
vi a(k+1),b(k+1);
rep(i,0,k){
cin>>a[i]>>b[i];
c[a[i]]++,d[b[i]]++;
s.insert({a[i],b[i]});
}
vi f,e;
for(int i=1;i<=n;i++)y=max(y,c[i]);
for(int i=1;i<=m;i++)x=max(x,d[i]);
for(int i=1;i<=n;i++){
	if(c[i]==y){
		e.pb(i);
	}
}
for(int i=1;i<=m;i++){
	if(d[i]==x){
		f.pb(i);
	}
}
int ans=x+y-1;
for(int i=0;i<sz(e);i++){
	for(int j=0;j<sz(f);j++){
		if(s.count({e[i],f[j]})==0){
			cout<<ans+1;
			return;
		}
	}
}
cout<<ans;
}
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t=1;
 // cin>>t;
  while(t--){
  	solve();
  }
  return 0;
}
