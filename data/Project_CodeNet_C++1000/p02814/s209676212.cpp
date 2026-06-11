#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll gcd(ll a,ll b){
   if(a%b==0){
       return(b);
   }
   else{
       return(gcd(b,a%b));
   }
}

ll lcm(ll a,ll b){
   return a/gcd(a,b)*b;
}

int main()
{
  ll N,M; cin>>N>>M;
  vector<ll> b(N); rep(i,N) {cin>>b[i]; b[i]/=2;}
  
  if(N==1){
    ll ans=M/b[0];
    ans=(ans+1)/2;
    cout<<ans<<endl;
    return 0;
  }
  
  //N>=2;
  vector<ll> cou(N);
  rep(i,N){
    ll sb=b[i];
    ll count=0;
    while(sb%2==0){
      sb/=2,count++;
    }
    cou[i]=count;
  }
  int judge=0;
  rep(i,N-1) if(cou[i]!=cou[i+1]) judge=1;
  
  if(judge){cout<<0<<endl; return 0;}
  
  ll B=1;
  rep(i,N) B=lcm(B,b[i]);
  ll ans=M/B;
  ans=(ans+1)/2;
  cout<<ans<<endl;
  return 0;
}
