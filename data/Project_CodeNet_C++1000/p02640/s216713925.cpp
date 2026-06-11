#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  ll N, M;
  cin >> N >> M;
  if(M % 2 == 0) {
    if(N * 2 <= M && M <= N * 4) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    cout << "No" << endl;
  }
}