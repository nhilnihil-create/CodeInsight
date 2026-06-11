#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

ll N;
string s;
void dfs(ll index, char M)
{
  if (index == N) {
    cout << s << "\n";
    return;
  }
  for (ll i = 0; i <= M - 'a' + 1; ++i) {
    s[index] = (char)('a' + i);
    dfs(index + 1, max(M, (char)('a' + i)));
  }
}

int main()
{
  cin >> N;
  s = "";
  for (ll i = 0; i < N; ++i) {
    s += 'a';
  }
  dfs(1, 'a');
}
