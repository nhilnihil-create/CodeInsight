#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void){
  double l;
  cin >> l;
  l /= 3;
  double ans = l*l*l;
  printf("%.10f",ans);
  return 0;
}
