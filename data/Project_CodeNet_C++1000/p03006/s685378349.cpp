#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

struct diverta2019_b{
  int N;
  vector<pair<ll, ll>> D;
  
  void init(){
    cin >> N;
    D.resize(N);
    for(auto&& x:D){
      cin >> x.first >> x.second; 
    }
  }
  
  void solve(){
    init();
    sort(D.begin(), D.end());
    int ans = N == 1 ? 1 : 51;
    for(int i=0;i<N;i++){
      for(int j=i+1;j<N;j++){
        int p = D[j].first - D[i].first;
        int q = D[j].second - D[i].second;
        vector<bool> ok(N, false);
        int cost = 0;
        for(int f=0;f<N;f++){
          if(!ok[f])cost++;
          ok[f] = true;
          for(int t=0;t<N;t++)
            if(D[f].first + p == D[t].first
               && D[f].second + q == D[t].second)
              ok[t] = true;
        }
        // cerr << " " << i << " " << j;
        // cerr << " " << p << " " << q;
        // cerr << " " << cost << endl;
        ans = min(ans, cost);
      }
    }
    cout << ans << endl;
  }
  
};

int main(){
  diverta2019_b ins;
  ins.solve();
}