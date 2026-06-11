#include <bits/stdc++.h>
#include <math.h>
#include <cmath>

using namespace std;
using ll =long long;
using vi = vector<int>; 
using vvi = vector<vi>; 
using vl = vector<ll>; 
using vvl = vector<vl>; 
using vs = vector<string>;
using vvs = vector<vs>; 
using vc = vector<char>;
using vvc = vector<vc>; 
using vb = vector<bool>;
using vvb = vector<vb>; 

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
typedef pair<int, int> PR;

#define rep(i,n) ;for( int i =0; i < n ; i ++)
#define all(a) a.begin(),a.end()
#define pb(a) push_back(a)
#define pd(a) printf("%.10f\n",a)
#define mem(a) memset(a,0,sizeof(a))
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pri(a)  printf("%.14lf\n",a);
#define MOD 1000000007
bool is_int_lround(double x){
  return std::lround(x)==x;
}
ll keta(ll x){
  ll n=0;
  while(x>0){
    x /=10 ;
    n ++;
  }
  return n;
}

ll conbi(int n,int m){
  
  cin>>n>>m;
  vector<ll> a(100);
  a[0] =1;
  for(int i=0;i<14;i++){
    a[i+1]=a[i]*(i+1);
  }
  return a[n] /(a[m] *a[n-m]);
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;//繰り返し二乗法
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll kaijo(ll x){
  ll z=1;
  if(x==0){
    return 1;
  }
  while(x>0){
    z *=x;
    z %=MOD;
    x--;
  }
  return z;
}
ll yakusu_num(ll n){
  vl yakusu(n+1,1);
  for(ll i=2;i*i<=n;i++){ 
    while(n%i==0){
      n /=i;
      yakusu[i]++;
    }
  }
  if(n!=1)yakusu[n]++;
  ll num=1;
  for(ll i=0;i <=n;i++){
    num*=yakusu[i];
  }
  return num;
}
 

//cout<<""<<endl;
int main(){
  ll N,M;cin>>N>>M;
  vl A(N),B(N);
  vvl G(100001);
  rep(i,N){
    cin>>A[i]>>B[i];
    G[A[i]].pb(B[i]);
  }
  ll ans=0;
    priority_queue<ll> qu;
  for(int i=1;i<=M;i++){
    for(int j=0;j<G[i].size();j++){
      ll r=G[i][j];
      qu.push(r);
    }
    if(!qu.empty()){
      ll p=qu.top();
      qu.pop();
      ans +=(ll)p;
    }
    
  }

  cout<<ans<<endl;
}



