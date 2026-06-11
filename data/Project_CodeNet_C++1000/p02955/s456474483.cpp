#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=110000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll gcd(ll x, ll y){
  if(x%y==0)return y;
  return gcd(y,x%y);
}
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);  
  
  ll n,k;
  cin >> n >> k;
  vl a(n);
  
  ll sum_a=0;
  rep(i,n){
    cin >> a[i];
    sum_a+=a[i];
  }
  vector<ll>yakusu;
  for(ll i=1;i*i<=sum_a;i++){
    if(sum_a%i==0){
      yakusu.push_back(i);
      ll j=sum_a/i;
      if(j!=i)yakusu.push_back(j);
    }
  }
  
  ll ans=1;
  rep(i,yakusu.size()){
    ll d=yakusu[i];
    vector<ll>r;
    rep(j,n){
      if(a[j]%d!=0)r.push_back(a[j]%d);
    }
    sort(r.begin(),r.end());
    
    ll need=1e18;
    ll sum_l=0,sum_r=0;
    rep(i,r.size())sum_r+=d-r[i];
    rep(i,r.size()){
      sum_r-=d-r[i];
      sum_l+=r[i];
      need=min(need,max(sum_r,sum_l));
    }  
    if(need<=k)chmax(ans,d);
  }
  cout << ans << endl;
  return 0;
}