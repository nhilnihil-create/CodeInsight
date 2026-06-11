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
  int s = 0;
  rep(i,N) s ^= A[i];
  rep(i,N){
    A[i] ^= s;
    cout << A[i] << endl;
  }
}
