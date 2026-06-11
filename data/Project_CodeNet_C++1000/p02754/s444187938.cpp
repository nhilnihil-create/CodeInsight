#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  ll N, A, B;
  cin >> N >> A >> B;

  ll amari = N % (A + B);  //周期からはみ出た個数
  ll s = min(amari, A);
  ll ans = N / (A + B) * A + s;
  cout << ans << endl;
}
