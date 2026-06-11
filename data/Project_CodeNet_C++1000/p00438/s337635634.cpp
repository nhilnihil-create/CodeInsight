#include <stdio.h>
#include <cstring>

main(){
  while(1){

    int w,h;
    scanf("%d%d", &w,&h);

    if(w==0&&h==0) break;

    int dp[w][h];

    memset(dp, -1, sizeof(dp));

    int n;
    scanf("%d", &n);

    int x,y;
    for(int i=0;i<n;i++){
      scanf("%d%d",&x,&y);
      dp[x-1][y-1] = 0;
    }

    int k=1;
    for(int i=0;i<w;i++){
      if(!dp[i][0]) k=0;
      dp[i][0] = k;
    }
    k=1;
    for(int i=0;i<h;i++){
      if(!dp[0][i]) k=0;
      dp[0][i] = k;
    }

    // for(int i=0;i<w;i++){
    //   for(int j=0;j<h;j++){
    //     printf("%2d ", dp[i][j]);
    //   }
    //   puts("");
    // }

    for(int i=1;i<w;i++){
      for(int j=1;j<h;j++){
        if(dp[i][j]==-1){
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }
    }

    printf("%d\n", dp[w-1][h-1]);

  }
}