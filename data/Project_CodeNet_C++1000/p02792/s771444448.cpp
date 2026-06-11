#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin>>N;
  int DP[N+1];
  int temp=0;
  int l=0;
  int r=0;
  for(int i=1;i<=N;i++){
    if(i<10){
      DP[i]=i*10+i;
      continue;
    }
    if(i%10==0){
      DP[i]=-1;
      continue;
    }
    temp=i;
    r=temp%10;
    while(temp>0){
      l=temp;
      temp/=10;
    }
    DP[i]=l*10+r;
  }
  map<int,int>mp;
  for(int i=1;i<=N;i++){
    mp[DP[i]]++;
  }  
  int ans=0;
  for(int i=1;i<=N;i++){
    temp=(DP[i]%10)*10+DP[i]/10;
    ans+=mp[temp];
  }
  cout<<ans<<endl;
  return 0;
}