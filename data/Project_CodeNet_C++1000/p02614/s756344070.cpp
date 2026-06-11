#include <bits/stdc++.h>

using namespace std;

int main()
{
  int i,j,k;
  int H,W,K;
  int ans;
  int black;
  scanf("%d %d %d",&H,&W,&K);
  char S[H+1][W+1];
  for(i=0;i<H;i++){
    scanf("%s",S[i]);
  }

  ans = 0;
  black = 0;
  for(int temp=0;temp<(1<<H);temp++){
    for(int temp2=0;temp2<(1<<W);temp2++){
      for(i=0;i<H;i++){
        for(j=0;j<W;j++){
          if( !(temp2&(1<<j)) && !(temp&(1<<i)) && S[i][j]=='#' ){
            black += 1;
          }
        }
      }
        if( black == K ){
          ans++;
        }
        black = 0;
    }
  }

  cout << ans << endl;
  return 0;
}
