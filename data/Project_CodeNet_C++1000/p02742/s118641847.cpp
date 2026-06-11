#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
int64_t MOD=10000007;

int main() {
  int64_t H,W;
  cin>>H>>W;
  int64_t a=H*W;
  if(a%2==0)a/=2;
  else a=(a+1)/2;
  if(H!=1&&W!=1)cout<<a;
  else cout<<1;

  
  
}
