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


ll f(ll a,ll b){
  ll c=0;
  while(a||b){
    a/=10;
    b/=10;
    c++;
  }
  return c;
}


int main()
{ 

IOS;

ll n,k;

cin>>n>>k;

ll c=1;

string s;cin>>s;

for(int i=1;i<n;i++){
  if(s[i]!=s[i-1])c++;
}

ll ans=n-c;


ll y=max(0ll,c-2);

if(y&1){
  ll d=y/2+1;

ans+=2*min(d,k);
 chmin(ans,n-1);
cout<<ans;
return 0;
}

else {

ll d=y/2;
if(k>=d+1){
  ans+=2*d+1;
  chmin(ans,n-1);
  cout<<ans;
  return 0;
}
else if(k==d){
ans+=2*d;
 chmin(ans,n-1);
cout<<ans;
return 0;
}
else {
ans+=2*k;
cout<<ans;
 chmin(ans,n-1);
return 0;
}

}

//end_routine();

return 0;
 
}
