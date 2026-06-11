#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  ll A, B, C, D;
  cin >> A >> B >> C >> D;
  auto f = [&](ll N){
    return N - (N / C + N / D - N / lcm(C, D));
  };
  cout << f(B) - f(A - 1) << endl;
  return 0;
}
