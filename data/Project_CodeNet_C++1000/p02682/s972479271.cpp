#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using p = pair<int, int>;

int main() {
  int A,B,C,K;
  cin >> A >> B >> C >> K;
  if (K <= A + B) cout << min(K, A) <<endl;
  else{
    cout << A - (K - A - B) << endl;
  }
}