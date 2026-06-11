#include "bits/stdc++.h"
using namespace std;
using ll = long long;
// #include "debug.h"
#define debug(...) 42

const ll inf = 1e17L;

const int mod = 1e9 + 7;
void solve(int testCaseID) {

   int n, k;
   cin >> n >> k;
   vector <int> v(n);
   vector <pair <int, int> > p(n);

   for(int i = 0; i < n; i++) {
      cin >> v[i];
      p[i] = {v[i], i};
   }

   sort(p.begin(), p.end());

   ll inv_cnt = 0;
   for(int i = 0; i < n; i++) {
      for(int j = i + 1; j < n; j++) {
         inv_cnt += v[i] > v[j];
      }
   }

   inv_cnt = (inv_cnt * k) % mod;
   debug(inv_cnt);
   for(int i = 0; i < n; i++) {
      for(int j = 0; j < i; j++) {
         if(p[j].first < p[i].first) {
            inv_cnt += (k * 1LL * (k - 1)) / 2;
            inv_cnt %= mod;
            debug(inv_cnt);
         }
      }
   }

   cout << inv_cnt << endl;

} 

int main() {
   cin.tie(0);
   cin.sync_with_stdio(0);
   int testcase = 1;
   // cin >> testcase;

   for(int i = 0; i < testcase; i++) {
      solve(i + 1);
   }
   return 0;
}
