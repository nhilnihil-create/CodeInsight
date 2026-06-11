#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair <int, int>;
const double PI = acos(-1);
const ll MOD = 1000000007;

int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> baito(100001, vector<int>(1,0));
  rep(i, N){
    int A, B;
    cin >> A >> B;
    baito[A].push_back(B);
  }

  ll ans = 0;

  priority_queue<int> choice;

  rep(i, M) {
    rep(j, baito[i+1].size()) choice.push(baito[i+1][j]);
    ans += choice.top();
    choice.pop();
  }

  cout << ans << endl;

}
