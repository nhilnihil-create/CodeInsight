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
   vector<int> b(n);
   for (int i = 0; i < n; i++)
      scanf("%d%d", &a[i], &b[i]);
   sort(all(a));
   sort(all(b));
   if (n % 2 == 0) {
      printf("%d", b[(n - 1) / 2] + b[(n + 1) / 2] - 
         a[(n - 1) / 2] - a[(n + 1) / 2] + 1);
   } else {
      printf("%d", b[(n - 1) / 2] - a[(n - 1) / 2] + 1);
   }
   return 0;
}