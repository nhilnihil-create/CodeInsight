#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
const ll MOD2=998244353;
const double PI=3.14159265358979;
const ll INF= pow(10,18);
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
string abc="abcdefghijklmnopqrstuvwxyz";
string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll n,d,a;
  cin >> n >> d >> a;
  vector<P> p(n+1,{INF,0});
  vl x(n+1,INF),h(n+1,0);
  rep(i,n){
    cin >> x[i] >> h[i];
    h[i]=(h[i]-1)/a+1;
    p[i].first=x[i];
    p[i].second=h[i];
  }
  rep(i,n){
    p[i].first=x[i];
    p[i].second=h[i];
  }
  sort(p.begin(),p.end());
  vl DIS(n);
  vl delta(n,0);
  ll atk=0;
  ll R=0;
  rep(i,n){
    while(p[R+1].first<=2*d+p[i].first){
      R++;
    }
    DIS[i]=R;
  }
  ll cnt=0;
  rep(i,n){
    if(delta[i]<0){
      atk+=delta[i];
    }
    if(p[i].second>atk){
      cnt+=(p[i].second-atk);
      delta[DIS[i]+1]-=p[i].second-atk;
      atk=p[i].second;
    }
  }
  cout << cnt << endl;
}