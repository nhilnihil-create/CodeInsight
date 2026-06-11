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
const int N = 1e7 + 4;
int c[N];
int main() {
#ifndef ONLINE_JUDGE
#endif
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n;
   cin >> n;
   for(int i= 1 ; i <= n ; ++i){
      for(int j = i ; j <= n ; j += i){
         c[j]++;
      }
   }
   long long rs = 0;
   for(int i = 1 ; i <= n ; ++i)
      rs += (1ll * i * c[i]);
   cout << rs << "\n";
}