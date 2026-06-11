//ループ検知

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N; ll K;
  cin >> N >> K;
  vector <int> A(N);
  rep(i,N){
    cin >> A[i];
  }

  vector <int> s;  //訪れた頂点
  vector <int> ord(N + 1, -1);  //各頂点を訪れた順番
  int cycle = 1; //周期
  int initial = 0;  //ループに入るまでの回数
  {
    int v = 1;  //頂点
    //まだ訪れていないならループを続ける
    while (ord[v] == -1){
      ord[v] = s.size();
      s.push_back(v);
      v = A[v - 1];
    }
    cycle = s.size() - ord[v];
    initial = ord[v];
  }
  if (K < initial) cout << s[K] << endl;
  else {
    K -= initial;
    K %= cycle;
    cout << s[initial + K] << endl;
  }
  return 0;
}
