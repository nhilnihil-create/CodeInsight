#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,T;
  cin>>N>>T;
  vector<pair<int,int>> p(N);
  for(int i=0;i<N;i++){
    int a,b;
    cin>>a>>b;
    p.at(i)=make_pair(a,b);
  }
  sort(p.begin(),p.end());
  vector<vector<int>> dp(N,vector<int>(T));
  for(int i=1;i<N;i++){
    for(int j=0;j<T;j++){
      if(j>=p.at(i-1).first){
        dp.at(i).at(j)=max(dp.at(i-1).at(j),p.at(i-1).second+dp.at(i-1).at(j-p.at(i-1).first));
      }
      else{
        dp.at(i).at(j)=dp.at(i-1).at(j);
      }
    }
  }
  int Z=0;
  for(int i=0;i<N;i++){
    Z=max(Z,p.at(i).second+dp.at(i).at(T-1));
  }
  cout<<Z<<endl;
                           
              
}