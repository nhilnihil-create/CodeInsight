#include <bits/stdc++.h>
using Int = int64_t;
using UInt = uint64_t;
using C = std::complex<double>;
#define rep(i, n) for(Int i = 0; i < (Int)(n); ++i)
#define guard(x) if( not (x) ) continue;
#ifndef LOCAL_
#define fprintf if( false ) fprintf
#endif

int main() {
   Int v, e;
   std::cin >> v >> e;
   std::vector<Int> ss(e), ts(e);
   rep(i, e) std::cin >> ss[i] >> ts[i];
   std::vector<std::vector<Int>> nexts(v);
   rep(i, e) {
      Int s = ss[i], t = ts[i];
      nexts[s].emplace_back(t);
   }
   std::vector<Int> xs(v, -1);
   Int id = 0;
   std::function<void(Int,Int)> dfs = [&](Int i, Int prev) {
      if( xs[i] != -1 ) return;
      xs[i] = -2;
      for(Int k : nexts[i]) {
         guard( k != prev );
         if( xs[k] == -1 ) {
            dfs(k, i);
         }
      }
      xs[i] = id; id += 1;
   };
   rep(i, v) dfs(i, -1);
   std::vector<Int> ys(v);
   rep(i, v) ys[xs[i]] = i;
   std::reverse(ys.begin(), ys.end());
   rep(i, v) printf("%ld\n", ys[i]);
}

