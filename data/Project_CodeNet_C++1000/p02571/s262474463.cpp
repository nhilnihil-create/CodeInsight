#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD1 1000000007
#define MOD2 1000000009
#define FOR(a,b) for(int i=a;i<b;i++)
#define nl "\n"

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s, t;
  cin >> s >> t;
  int ans = t.size();
  for (int i = 0; i <= s.size() - t.size(); i++)
  {
    int diff = 0;
    for (int j = 0; j < t.size(); j++)
    {
      if (t[j] != s[i + j])
        diff++;
    }
    ans = min(ans, diff);
  }
  cout << ans << endl;
  return 0;
}

