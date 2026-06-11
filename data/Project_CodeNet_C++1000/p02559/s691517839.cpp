#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;

int main() {
  long n,q,aa,x,y,z;
  cin >> n >> q;
  fenwick_tree<long> a(n);
  for(long i=0;i<n;i++) {
    cin >> aa;
    a.add(i,aa);
  }
  for(long i=0;i<q;i++) {
    cin >> x >> y >> z;
    if(x==0) a.add(y,z);
    else cout << a.sum(y,z) << endl;
  }
}