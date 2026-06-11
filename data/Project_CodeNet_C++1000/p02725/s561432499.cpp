#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int k,n;
  cin >> k >> n;
  int a[n-1] = {0};
  rep(i,n) cin >> a[i];
  int c=0;
  for(int i=0;i<n-1;++i){
    c = max(c,a[i+1]-a[i]);
  }
  c = max(c,k-a[n-1]+a[0]);
  printf("%d",k-c);
  return 0;
}
