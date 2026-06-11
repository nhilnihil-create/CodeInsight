#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  int N;
  cin>>N;
  int A[100000];
  
  //入力
  for(int i=0;i<=N;i++){
    cin>>A[i];
  }
  
  //各深さの最低・最高の出力
  int maxnode[N+1];
  int minnode[N+1];
  minnode[N]=A[N];
  maxnode[N]=A[N];
  
  for(int i=N;i>0;i--){
    //cout<<i<<" "<<minnode[i]<<" "<<maxnode[i]<<endl;
    minnode[i-1]=(minnode[i]+1)/2+A[i-1];
    maxnode[i-1]=maxnode[i]+A[i-1];
  }
  //cout<<0<<" "<<minnode[0]<<" "<<maxnode[0]<<endl;
  //構成可能かを判定
  if(!(minnode[0]<=1 && maxnode[0]>=1)){
    cout<<-1<<endl;
    return 0;
  }
  
  //最大ノードの判定
  int ans[N+1];
  ans[0]=1;
  for(int i=1;i<=N;i++){
    ans[i]=min((ans[i-1]-A[i-1])*2,maxnode[i]);
  }
  int sum=0;
  for(int i=0;i<=N;i++){
    //cout<<i<<" "<<ans[i]<<endl;
    sum+=ans[i];
  }
  cout<<sum<<endl;
  return 0;
}
