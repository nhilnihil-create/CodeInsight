//FIRST THINK THEN CODE.

#include <bits/stdc++.h>
 
 
using namespace std;
 
typedef long long ll;
 
#define MOD 998244353
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
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
ll newmod(ll a,ll b)
 {
  return ((a%b)+b)%b;
}
 
 
ll powM(ll a,ll b,ll m )
{ 
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

const ll N=3e5+5;

ll dp[N][21];

int main()
{ 

IOS;


ll n,k;cin>>n>>k;

ll sum=0;

vl a(n+1);

FOR(i,n){
  cin>>a[i+1];
  sum+=a[i+1];
}

vl d;

for(int i=1;i*i<=sum;i++){
  if(sum%i==0){
    d.pb(i);
    d.pb(sum/i);
  }
}

sort(all(d),greater<>());


for(int i=0;i<d.size();i++){
  ll x=d[i];
  bool allowed=0;
  vl temp(n+1);
  for(int j=1;j<=n;j++){
     temp[j]=a[j]%x;
  }
  sort(all(temp));

/*if(x==7){
  for(auto p:temp)cout<<p<<" ";
cout<<endl;
}
*/
  for(int j=1;j<=n;j++){
    temp[j]+=temp[j-1];
    }

    for(int j=0;j<=n;j++){
      ll left=temp[j];
      if(left>k)break;
      ll right=x*(n-j) -(temp[n]-temp[j]);
      if(left==right){
        allowed=1;
        break;
      }
    }

if(allowed){
  cout<<x<<endl;
  return 0;
}
}


cout<<1<<endl;







return 0;
 
}

