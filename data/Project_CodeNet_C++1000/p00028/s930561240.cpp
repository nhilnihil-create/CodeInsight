#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,n=100,ma=0,memo[101]={};
  while(scanf("%d",&a)!=EOF && n--){
    memo[a]++;
    ma=max(ma,memo[a]);
  }
  for(int i=0;i<=100;i++){
    if(memo[i]==ma)cout<<i<<endl;
  }
  return 0;
}