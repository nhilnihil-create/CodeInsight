#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};

//証言をグラフの形で保持する
int g[15][15];

int main(void){
  int N;
  cin >> N;
  rep(i,N)rep(j,N) g[i][j] = -1;  //初期化
  int A[N];
  rep(i,N){
    cin >> A[i];
    rep(j, A[i]){
      int a, x;
      cin >> a >> x;
      a--;
      g[i][a] = x;  //iからaへの証言がx
    }
  }

  int ans = 0;  //正直者の数の最大値
  rep(s,1<<N){
    vector <int> d(N);  //正直者 or 不親切の割り当て
    rep(i,N){
      if (s>>i&1){
        d[i] = 1;
      }
    }
    bool ok = true;  //これがtrueのままだったらその割り当てはok
    //i番目の人が正直者だったらその人の全部の証言を確認する
    rep(i,N){
      if (d[i]){
        rep(j,N){
          if (g[i][j] == -1) continue;
          if (g[i][j] != d[j]) ok = false;
        }
      }
    }
    //sの1の数を数える
    if (ok) ans = max(ans, __builtin_popcount(s));
  }
  cout << ans << endl;
  return 0;
}
