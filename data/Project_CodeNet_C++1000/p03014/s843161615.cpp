//FIRST THINK THEN CODE.

#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll;
 
//#define MOD 998244353
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define rrep(i,a,b) for(ll i=a;i>b;--i)
#define FOR(i,n)  for(ll i=0;i<n;i++)
#define vi vector<int>
#define vl vector<ll>
#define ld long double
#define vvi vector<vector<int>>
#define vvl vector<vector<long long>>
#define pii pair<int,int>
#define pll pair<long,long>
#define vpii vector<pii>
#define vpll vector<pll>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define d3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define d4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define PI 3.1415926535897932384626433832795
#define fix(f,n) fixed<<setprecision(n)<<f
#define all(x) x.begin(),x.end()
#define rev(p) reverse(p.begin(),p.end());
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define popcount(x) __builtin_popcountll(x)
#define sz(x) ((ll)x.size())
const ll M=1000000007;
const ll MM=998244353;
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";

 
ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}
 
 
ll powM(ll a,ll b,ll m )
{ 
  if(a<=0)return 0;
  a%=m;
  if(!b)return 1;
  ll ans=1LL;
  while(b)
  {
    if(b&1)ans=ans*a%m;
    a=a*a%m;
    b>>=1;
  }
 
return ans;
}


 
ll poww(ll a,ll b)
{ 
  
  ll ans=1;
  while(b)
  {
    if(b&1)ans=ans*a;
    a=a*a;
    b>>=1;
  }
 
return ans;

}

template<typename T,typename F>
void chmax( T &a,F b){
  if(b>a)a=b;
}

template<typename T,typename F>
void chmin( T &a,F b){
  if(b<a)a=b;
}

const ll N=1e5+5;

struct segtree{

ll size;

vl sums;

void init(ll n){
  size=n+1;

  sums.resize(2*size,0);
}

void allot(ll n){
  size=1;
  while(size<=n)size*=2;

//vl sums(size,0);

  sums.resize(2*size,0);

}

void build(vl& a,ll x,ll lx,ll rx){
if((rx-lx)==1)
{
 if( lx<sz(a))
  sums[x]=a[lx];

return;
}

ll m=(lx+rx)/2;

/*
   x
  / \
 /   \
2*x+1,2*x+2

*/
build(a,2*x+1,lx,m);  //[lx,m)

build(a,2*x+2,m,rx);  // [m,rx)

sums[x]=sums[2*x+2]+sums[2*x+1];

}

void build(vl& a){
  build(a,0,0,size);
}


void add(ll i,ll v,ll x,ll lx,ll rx){

  if(rx-lx==1){
    sums[x]+=v;
    return;
  }

  ll m=(lx+rx)/2;

if(i<m)add(i,v,2*x+1,lx,m);
else add(i,v,2*x+2,m,rx);

sums[x]=sums[2*x+1]+sums[2*x+2];

}

void add(ll i, ll v){
  add(i,v,0,0,size);
}


void set(ll i,ll v,ll x,ll lx,ll rx){

  if(rx-lx==1){
    sums[x]=v;
    return;
  }

  ll m=(lx+rx)/2;

if(i<m)set(i,v,2*x+1,lx,m);
else set(i,v,2*x+2,m,rx);

sums[x]=sums[2*x+1]+sums[2*x+2];

}

void set(ll i, ll v){
  set(i,v,0,0,size);
}

ll calc(ll l,ll r,ll x,ll lx,ll rx){
  ll tot=0;

if(lx>=r||rx<=l)return 0;
else if(lx>=l&&rx<=r)return sums[x];

ll m=(lx+rx)/2;

return calc(l,r,2*x+1,lx,m)+calc(l,r,2*x+2,m,rx);

}

ll calc(ll l,ll r){
  return calc(l,r,0,0,size);
}

ll find(ll k,ll x,ll lx,ll rx){

if(rx-lx==1)return lx;

ll m=(lx+rx)/2;

if(sums[2*x+1]>=k){
  return find(k,2*x+1,lx,m);
}
else {
  return find(k-sums[2*x+1],2*x+2,m,rx);
}

}

ll find(ll k){
  return find(k,0,0,size);
}


};

char a[2005][2005];

int main()
{ 

IOS;

ll h,w;

cin>>h>>w;

vvl c1(h,vl(w));

FOR(i,h){
  ll cnt=0;
  FOR(j,w){
    cin>>a[i][j];
    if(a[i][j]=='.'){
      c1[i][j]=cnt;
      cnt++;
    }
    else {
      cnt=0;
      //c1[i]=0;
    }

}
}

FOR(i,h){
  ll cnt=0;
  for(int j=w-1;j>=0;j--){
    if(a[i][j]=='.'){
      c1[i][j]+=cnt;
      cnt++;
    }
    else {
      cnt=0;
    }
  }
}

FOR(i,w){
  ll cnt=0;
  FOR(j,h){
  if(a[j][i]=='.'){
    //cnt++;
    c1[j][i]+=cnt;
    cnt++;
  }
    else {
      cnt=0;
    }
}
}

FOR(i,w){
  ll cnt=0;
for(int j=h-1;j>=0;j--){
  if(a[j][i]=='.'){
    c1[j][i]+=cnt;
    cnt++;
  }
  else {
    cnt=0;
  }
}
}

ll ans=0;

FOR(i,h){
  FOR(j,w){
    ll x=c1[i][j];
    if(a[i][j]=='.')x++;
    else x=0;
    ans=max(ans,x);
  }
}


cout<<ans;

//end_routine();

return 0;
 
}
