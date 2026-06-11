#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  int s, w;
  cin >> s >> w;
  if(s > w) puts("safe");
  else puts("unsafe");
  return 0;
}