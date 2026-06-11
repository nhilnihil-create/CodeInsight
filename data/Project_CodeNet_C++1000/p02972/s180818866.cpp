#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0;i < (int)(n);i++)
typedef long long ll;

int a[200006];
int sum[200006];
int b[200006];

int main(){
  int n;
  int i,j;
  int m = 0;

  scanf("%d", &n);
  for(i = 1;i <= n;i++){
    scanf("%d", &a[i]);
    sum[i] = b[i] = 0;
  }

  vector <int> ans;

  for(i = n;i >= 1;i--){
    int sum = 0;
    for(j = i;j <= n;j += i){
      sum += b[j];
    }

    if(a[i] == 0){
      if(sum % 2 == 1){
        b[i] = 1;
        ans.push_back(i);
      }
    }

    else {
      if(sum % 2 == 0){
        b[i] = 1;
        ans.push_back(i);
      }
    }
  }

  printf("%d\n", ans.size());

  for(i = 0;i < ans.size();i++){
    printf("%d\n", ans[i]);
  }

  return 0;
}