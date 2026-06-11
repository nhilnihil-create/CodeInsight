#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long dp[11][11][11];
int main(){
  #define int long long
  int N;
  cin>>N;
  string S;
  cin>>S;
  int ans=0;
  for(int i=0;i<=9;i++){
    for(int j=0;j<=9;j++){
      for(int k=0;k<=9;k++){
        int check=0;
        for(int h=0;h<N;h++){
          if(check==0){
            if(S.at(h)-'0'==i){
              check++;
              continue;
            }
          }
          if(check==1){
            if(S.at(h)-'0'==j){
              check++;
              continue;
            }
          }
          if(check==2){
            if(S.at(h)-'0'==k){
              check++;
              break;
            }
          }
        }
        if(check==3 && dp[i][j][k]==0){
          dp[i][j][k]=1;
          ans++;
        }
      }
    }
  }
  cout<<ans<<endl;
}