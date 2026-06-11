#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,p,q,r;
  cin >> p >> q >> r;

  if(p>=q && p>=r)
  {
    a = q + r;
  }
   if(q>=p && q>=r)
  {
    a = p + r;
  }
     if(r>=p && r>=q)
  {
    a = p + q;
  }
  cout << a;
}