#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, D;
    cin >> N >> D;
    int ans = (N + 2 * D) / (2 * D + 1);
    cout << ans << endl;

  return 0;
}
