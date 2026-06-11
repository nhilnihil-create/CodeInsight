#include <bits/stdc++.h>
using namespace std;




int main(){
  int N,K;
  cin>>N>>K;
  
  vector<int> vec(N+1);
  for(int i=1;i<=N;i++){
    cin>>vec.at(i);
  }
  vector<int> rui(N+1);
  rui.at(0)=0;
  rui.at(1)=vec.at(1);
  for(int i=2;i<=N;i++){
    rui.at(i)=vec.at(i)+rui.at(i-1);
  }
  int deka=0;
  
  for(int i=1;i<=N-K+1;i++){
    int kari=0;
    kari+=rui.at(i+K-1)-rui.at(i-1);
    deka=max(kari,deka);
  }

  cout<<fixed<<setprecision(10)<<double((deka+K)/2.0)<<endl;
    

}