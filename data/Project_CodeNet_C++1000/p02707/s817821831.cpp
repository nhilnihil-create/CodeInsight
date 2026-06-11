#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;
  vector <int> cnt(N + 1);
  for (int i = 2; i <= N; i++){
    int a;
    cin >> a;
    cnt[a] ++;
  }
  for (int i = 1; i <= N; i++){
    cout << cnt[i] << endl;
  }
  return 0;
}
