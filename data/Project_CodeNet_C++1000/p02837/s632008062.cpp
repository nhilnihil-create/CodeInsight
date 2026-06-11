#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC147 C - HonestOrUnkind2
// 2020.06.19

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  vector<vector<pair<int, int> > > Axy(N, vector<pair<int, int> >());
  REP(i, N){
    int A; cin >> A;
    REP(j, A){
      int x, y; cin >> x >> y; x--;
      Axy[i].push_back({x, y});
    }
  }
  int ans = 0;
  REP(i, 1<<N){
    vector<int> check(N, 0);
    int res = 0;
    REP(j, N){
      if((i >> j) & 1){
        check[j] = 1;
        res++;
      }
    }
    bool flag = true;
    REP(j, N){
      if(check[j]){
        for(auto k : Axy[j]){
          if(check[k.first] != k.second){
            flag = false;
            break;
          }
        }
      }
      if(!flag) break;
    }
    if(flag){
      ans = max(ans, res);
    }
  }
  cout << ans << endl;
}