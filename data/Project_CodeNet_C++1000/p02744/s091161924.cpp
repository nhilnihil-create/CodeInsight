#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N;
void dfs(string s, char M)
{
  ll sl = s.size();
  if (sl == N) {
    cout << s << "\n";
    return;
  }
  for (ll i = 0; i <= M - 'a' + 1; ++i) {
    dfs(s + (char)('a' + i), max(M, (char)('a' + i)));
  }
}

int main()
{
  cin >> N;
  dfs("a", 'a');
}
