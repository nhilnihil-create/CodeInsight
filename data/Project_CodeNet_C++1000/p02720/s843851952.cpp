#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
  int K;
  cin>>K;
  long long dp[30][10];
  int judge=0;
  int a,b;
  for(int i=0;i<30;i++){
    for(int j=0;j<10;j++){
      if(i==0) dp[i][j]=1;
      else{
        if(j==0) dp[i][j]=dp[i-1][0]+dp[i-1][1];
        else if(j==9) dp[i][j]=dp[i-1][8]+dp[i-1][9];
        else dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
      }
      if(j!=0) judge+=dp[i][j];
      if(judge>=K){
        judge-=dp[i][j];
        a=i;
        b=j;
        i+=40;
        j+=20;
      }//if(judge<K)
    }
  }
  while(a>=0){
          cout<<b;
          if(a==0) cout<<endl;
          else{
            int x=max(0,b-1);
            while(x<=min(b+1,9)){
              if(judge+dp[a-1][x]<K){
               judge+=dp[a-1][x];
                x++;
              }
              else{
                b=x;
                x+=3;
              }
            }//while
          }
    a--;
    }//while
  return 0;
}