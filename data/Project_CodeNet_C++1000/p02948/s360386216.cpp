#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=1000000007;
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
  ll n,m;
  cin >> n >> m;
  vector<P> p(n);
  rep(i,n){
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin(),p.end());
  priority_queue<ll> pq;
  ll j=0;
  ll ans=0;
  rep(i,m+1){
    while(p[j].first==i){
      pq.push(p[j].second);
      j++;
    }
    if(pq.size()){
      ll t=pq.top();
      ans +=t;
      pq.pop();
    }
    else{
      continue;
    }
  }
  cout << ans << endl;
}