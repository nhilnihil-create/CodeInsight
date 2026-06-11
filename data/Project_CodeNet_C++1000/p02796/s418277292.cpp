#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
int n;
pair<int,int> p[100010];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x,l;
    cin >> x >> l;
    p[i].first = x + l;
    p[i].second = x - l;
  }
  sort(p,p+n);
  int ans = 0;
  int lft = -1e9-7;
  for (int i = 0; i < n; i++) {
    if (p[i].second < lft) continue;
    ans++;
    lft = p[i].first;
  }
  cout << ans << endl;
}

/*　【提出前に確認すること】
・コンパイルできるか
・テストケース試したか
・オーバーフローあるか
*/
