// ====================================
//   author: M_sea
//   website: https://m-sea-blog.com/
// ====================================
#include <bits/stdc++.h>
#include <atcoder/dsu>
#define file(x) freopen(#x".in","r",stdin); freopen(#x".out","w",stdout)
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
using namespace atcoder;
typedef long long ll;
 
const int N=200000+10;
 
int n,q;
dsu d(N);
 
int main() {
  scanf("%d%d",&n,&q);
  while (q--) {
    int op,u,v; scanf("%d%d%d",&op,&u,&v);
    if (!op) d.merge(u,v);
    else printf("%d\n",d.same(u,v));
  }
  return 0;
}