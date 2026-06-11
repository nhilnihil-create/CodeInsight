#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N,M;
  cin >> N >> M;
  ll h[N];
  for(ll i=0;i<N;i++){
    cin >> h[i];
  }
  vector<vector<int> >G(N);
  for(ll i=0;i<M;i++){
    ll a,b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  ll ans = 0;
  for(ll k=0;k<N;k++){
    bool ok=true;
    for(auto n:G[k]){
      if(h[k]<=h[n]) ok=false;
    }
    if(ok) ans++;
  }
  cout << ans << endl;
}
