#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;
  //n even
  //m odd
int main(){
  int n,m;
  cin >> n >> m;
  int t=n*(n-1)/2;
  t+=m*(m-1)/2;
  printf("%d",t);
  return 0;
}
