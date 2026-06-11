#include <cstdio>

int n, nums[100];

long long data[100][21];
int dp[100][21];

long long search(int i, int v){
  if(dp[i][v]) return data[i][v];

  if (i == n-1){
    if (v == nums[n-1]) return 1;
    else return 0;
  }

  long long r;

  if(v-nums[i] < 0){
    r = search(i+1, v+nums[i]);
  }else if(v+nums[i] > 20){
    r = search(i+1, v-nums[i]);
  }else{
    r = search(i+1, v+nums[i])+search(i+1, v-nums[i]);
  }
  
  dp[i][v] = 1;
  return data[i][v] = r;
}

main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d", nums+i);
  }

  for(int i=0;i<100;i++) for(int j=0;j<21;j++) dp[i][j] = 0;

  printf("%lld\n", search(1,nums[0]));
 }
  