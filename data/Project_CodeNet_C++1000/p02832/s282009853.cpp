#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main()
{
   int n;
   cin >> n;
   int now = 1;
   int tmp;
   int ans = 0;
   for (int i = 1; i <= n; i++) {
      cin >> tmp;
      if (now == tmp) now++;
      else ans++;
   }
   if (ans != n) cout << ans << endl;
   else cout << -1 << endl;
   return 0;
}