#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
  double n, ans;
  cin >> n;
  ans=(n-floor(n/2))/n;
  printf("%.6lf", ans);

  return 0;
}