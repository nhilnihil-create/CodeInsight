#include <iostream>

int n;
int cmb;
int dp[30];

int func(int now){
  if(now > n)
    return 0;
  if(now == n){
    dp[now] = 1;
    return 1;
  }


  return func(now+1) + func(now+2) + func(now+3);
}

int main(void){
  while(1){
    int ans;
    std::cin >> n;

    for(int i=0; i < 30; i++){
      dp[i] = -1;
    }

    if(n == 0){
      return 0;
    }

    cmb = 0;
    ans = func(0);

    std::cout << ans / 10 / 365 + 1 << std::endl;
  }
}