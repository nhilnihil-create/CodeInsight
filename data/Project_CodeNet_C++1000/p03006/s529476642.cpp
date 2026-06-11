#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 998244353
#define MAX 100
#define INF 800000000

int main(){
  int N;
  cin>>N;
  vector<pair<ll,ll>> xy(N);
  for(int i=0;i<N;i++){
    cin>>xy.at(i).first>>xy.at(i).second;
  }
  int ans=50;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      ll p=xy.at(j).first-xy.at(i).first;
      ll q=xy.at(j).second-xy.at(i).second;
      vector<bool> seen(N,false);
      int count=0;
      for(int k=0;k<N;k++){
        for(int l=0;l<N;l++){
          if((xy.at(k).first-xy.at(l).first==p)&&(xy.at(k).second-xy.at(l).second==q)){
            count++;
          }
        }
      }
      ans=min(ans,N-count);
    }
  }
  if(N==1){
    cout<<1<<endl;
  }else{
    cout<<ans<<endl;
  }
}
