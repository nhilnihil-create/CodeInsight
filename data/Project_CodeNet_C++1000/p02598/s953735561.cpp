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

bool check(vector<int> a, int m, int k) {
   int cuts = 0;
   for (int i : a)
      cuts += (i - 1) / m;
   return cuts <= k;
}

int main() {
   int n, k; scanf("%d%d", &n, &k);
   vector<int> a(n);
   for (int &i : a)
      scanf("%d", &i);
   int ans = -1;
   int l = 1;
   int r = 1;
   for (int i : a)
      r = max(r, i);
   while (l <= r) {
      int m = (l + r) / 2;
      if (check(a, m, k)) {
         ans = m;
         r = m - 1;
      } else {
         l = m + 1;
      }
   }
   printf("%d", ans);
   return 0;
}