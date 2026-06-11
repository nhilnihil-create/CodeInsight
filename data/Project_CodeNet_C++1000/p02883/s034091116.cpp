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
const int M=1000000007;
const int MM=998244353;
int begtime = clock();
#define end_routine() cout << "\n\nTime elapsed: " << (clock() - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n";

 
ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}
 
 
ll powM(ll a,ll b,ll m )
{ 
  if(m<=1)return 0;
  a%=m;
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

const ll N=5e5+5;

ll sp[N];

void fill(){
  for(int i=1;i<N;i++)sp[i]=i;

    for(int i=2;i<N;i++){
      for(int j=i;j<N;j+=i){
        if(sp[j]==j)sp[j]=i;
      }
    }
}

bool prime(ll x){
  if(x==2)return true;

for(ll i=2;i*i<=x;i++){
  if(x%i==0)return false;
}

  return true;
}

ll fac[N];

ll inv[N];

void gg(){
  fac[0]=inv[0]=1;

  for(int i=1;i<N;i++){
    fac[i]=fac[i-1]*i%M;
    inv[i]=powM(fac[i],M-2,M);
  }
}

ll c(ll a,ll b,ll M){
  if(b>a)return 0;

  return (fac[a]*inv[a-b]%M)*(inv[b])%M;
}

pll f(ll x){
  ll b=x%10;
  while(x>=10){
    x/=10;
  }
  return {x%10,b};
}

int main()
{ 

IOS;

ll n,k;

cin>>n>>k;

vl a(n),f(n),p(n);
FOR(i,n)cin>>a[i];

FOR(i,n)cin>>f[i];

sort(all(a));

rev(a);

sort(all(f));

ll mx=0;

FOR(i,n){
  p[i]=a[i]*f[i];
  mx=max(mx,p[i]);
 // d1(p[i]);
}




ll ans=1e18;

ll l=0,r=mx,m;

while(l<=r){
  m=(l+r)/2;

  ll cnt=0;


  for(int i=0;i<n;i++){
    ld temp=(p[i]-m)/(1.0*f[i]);

    ll x=ceil(temp);
    cnt+=max(x,0ll);
if(cnt>k)break;
  }

//  cout<<m<<" "<<cnt<<endl;

if(cnt<=k){
  ans=min(ans,m);
  r=m-1;
}
else l=m+1;

}

cout<<ans;


//end_routine();

return 0;
 
}
