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
  vector <int> A(N);
  rep(i,N) cin >> A[i];
  vector <int> s = A;
  sort(all(s));
  int mx = s[N - 1];
  int second = s[N - 2];
  rep(i,N){
    if (A[i] != mx) cout << mx << endl;
    else cout << second << endl;
  }
  return 0;
}
