#include<bits/stdc++.h>
using namespace std;
using p=pair<int,int>;
#define int long long
#define rep(i,N) for(int i=0;i<N;i++)

signed main(){
  int N;
  cin>>N;
  vector<int> city(N+1),brave(N);
  rep(i,N+1)cin>>city[i];
  rep(i,N)cin>>brave[i];
  int ans=0;
  rep(i,N){
    if(city[i]>=brave[i]){
      ans+=brave[i];
      continue;
    }
    else if(brave[i]<city[i]+city[i+1]){
      ans+=brave[i];
      city[i+1]-=brave[i]-city[i];
    }
    else{
      ans+=city[i]+city[i+1];
      city[i+1]=0;
    }
  }
  cout<<ans<<endl;
}