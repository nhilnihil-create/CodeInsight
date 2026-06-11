#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll N;
  cin >> N;
  vl a(N);
  rep(i,N){
    cin >> a[i];
  }
  vl num(N,0);
  per(i,N-1){
    ll j=i+1;
    ll k=2*j;
    ll cnt=0;
    while(k<=N){
      cnt+=num[k-1];
      k+=j;
    }
    cnt%=2;
    if((cnt-a[i])==0){
      num[i]=0;
    }
    else{
      num[i]=1;
    }
  }
  ll CNT=0;
  rep(i,N){
    if(num[i]==1){
      CNT++;
    }
  }
  cout << CNT << endl;
  rep(i,N){
    if(num[i]==1){
      cout << i+1 << endl;
    }
  }
}