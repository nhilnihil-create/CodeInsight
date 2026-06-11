#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int x1,x2,x3,x4,x5; cin >>x1 >>x2 >>x3 >>x4 >>x5;
  const int temp=1+2+3+4+5;
  int sum_val=x1+x2+x3+x4+x5;
  cout <<temp-sum_val <<endl;
  return 0;
}
