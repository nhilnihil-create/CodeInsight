#include<bits/stdc++.h>
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define rand() (rand() << 15 | rand())
using namespace std;
typedef long long  ll;
#define EPS 1e-9
#define PI acos(-1.0)

int main() {
#ifndef ONLINE_JUDGE
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n;
   cin >> n;
   vector<int> a(n);
   for(int i = 0 ; i < n ; ++i)
      cin >> a[i];

   sort(a.rbegin() , a.rend());
   long long rs = a[0];
   int rm = n - 2;
   for(int i = 1 ; rm && i < n ; ++i){
      rs += 1ll * min(2 , rm) * a[i];
      rm -= min(2 , rm);
   }
   cout << rs << "\n";
}