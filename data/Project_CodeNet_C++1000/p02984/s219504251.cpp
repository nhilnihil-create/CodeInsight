#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (int)(n);i++)
typedef long long ll;

int main(){
  int n;
  ll a[100006];
  ll sum = 0;

  scanf("%d", &n);

  int i;
  for(i = 1;i <= n;i++){
    scanf("%lld", &a[i]);
    sum += a[i];
  }

  ll sum2 = 0;

  for(i = 2;i <= n - 1;i += 2){
    sum2 += a[i];
  }

  ll ans[100006];

  ans[1] = sum - 2*sum2;

  for(i = 1;i < n;i++){
    ans[i + 1] = 2*a[i] - ans[i];
  }

  for(i = 1;i <= n;i++) printf("%lld\n", ans[i]);
  return 0;
}