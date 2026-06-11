#include <bits/stdc++.h>
using namespace std;
#define rep(i,s,n) for(int i = s;i < (int)(n);i++)
typedef long long ll;

int main(){
  int n,k;
  char s[100006];
  int i,ans;

  scanf("%d %d", &n, &k);
  scanf("%s", s);

  int cnt = 0;
  for(i = 0;i < n - 1;i++){
    if(s[i] != s[i + 1]) cnt++;
  }

  int init;
  init = n - cnt - 1;
  init += 2*k;

  ans = min(n - 1,init);

  printf("%d\n", ans);

  return 0;
}
