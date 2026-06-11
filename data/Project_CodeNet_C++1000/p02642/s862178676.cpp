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
   int n; scanf("%d", &n);
   vector<int> a(n);
   for (int &i : a)
      scanf("%d", &i);
   int m = *max_element(all(a));
   vector<int> check(m + 1);
   for (int i : a)
      check[i]++;
   int ans = 0;
   for (int i = 1; i <= m; i++) {
      if (check[i] >= 1) {
         if (check[i] == 1) ans++;
         for (int j = 2 * i; j <= m; j += i)
            check[j] = 0;
      }
   }
   printf("%d", ans);
   return 0;
}