#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
int INF = 1e9+7;
// const long long INF = 1LL<<60;

const int MAX_P = (1<<12)+1;

int main(){

  int N, M;
  cin >> N >> M;

  vector<int> price(M);
  vector<int> open_box(M);

  rep(i, M){
    int a, b;
    cin >> a >> b;
    price[i] = a;
    int tmp = 0;
    rep(_, b){
      int c;
      cin >> c;
      tmp += 1<<(c-1);
    }
    open_box[i] = tmp;
  }

  vector<int> prev(MAX_P, INF);
  prev[0] = 0;
  rep(i, M){
    vector<int> current(MAX_P, INF);
    rep(j, MAX_P){
      if(prev[j] == INF) continue;
      // 使わない
      current[j] = min(current[j], prev[j]);
      // 使う
      int next_j = (j | open_box[i]);
      if(MAX_P <= next_j) continue;
      current[next_j] = min(current[next_j], prev[j]+price[i]);
    }
    prev = current;
  }

  if(prev[(1<<N)-1] != INF){
    cout << prev[(1<<N)-1] << endl;
  }else{
    cout << -1 << endl;
  }

  return 0;
}
