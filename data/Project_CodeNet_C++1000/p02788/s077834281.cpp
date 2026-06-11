#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<ll, ll>;
const int mod = 1000000007;

int main(){
  int n, d, a;
  cin >> n >> d >> a;
  vector<P> V;
  rep(i, n){
    ll x, h;
    cin >> x >> h;
    V.push_back(P(x, h));
  }
  sort(V.begin(), V.end());
  ll damage=0;
  ll ans=0;
  multiset<int> M;
  vector<ll> mdamage(n+1);
  rep(i, n){
    if(M.find(i)!=M.end()){
      damage-=mdamage[i];
    }
    ll ix=V[i].first;
    ll ih=V[i].second;
    if(ih<=damage)continue;
    ans+=(ih-damage-1)/a+1;
    ll tmp=((ih-damage-1)/a+1)*a;
    damage+=tmp;
    int it=(int)(upper_bound(V.begin(), V.end(), P(ix+2*d, INF))-V.begin());
    M.insert(it);
    mdamage[it]+=tmp;
  }
  cout << ans << endl;
  return 0;
}
