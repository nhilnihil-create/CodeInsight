#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
 
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define endl '\n'
 
const ll MOD = 1000000007;
 
int main() {
   int x, y, a, b, c;
   scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);
   vector<int> p(a), q(b), r(c);
   for (int &i : p)
      scanf("%d", &i);
   for (int &i : q)
      scanf("%d", &i);
   for (int &i : r)
      scanf("%d", &i);
   sort(all(p), greater<int>());
   sort(all(q), greater<int>());
   sort(all(r), greater<int>());
   vector<int> sol;
   for (int i = 0; i < x; i++)
      sol.pb(p[i]);
   for (int i = 0; i < y; i++)
      sol.pb(q[i]);
   sort(all(sol), greater<int>());
   int cur = -1;
   while (!sol.empty() && cur < c - 1 
      && sol.back() < r[cur + 1]) {
      sol.pop_back();
      cur++;
   }
   ll ans = 0;
   for (int i : sol)
      ans += i;
   for (int i = 0; i <= cur; i++)
      ans += r[i];
   printf("%lld", ans);
   return 0;
}