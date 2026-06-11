#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M;cin>>N>>M;
  vector<int> H(N+1);
  for(int i=1;i<=N;i++) cin>>H.at(i);
  vector<bool> good(N+1,true);
  int count=N;
  for(int j=0;j<M;j++){
    int a,b;cin>>a>>b;
    if(H.at(a)>=H.at(b) && good.at(b)){
      good.at(b)=false;
      count--;
    }
    if(H.at(a)<=H.at(b) && good.at(a)){
      good.at(a)=false;
      count--;
    }
  }
  cout<<count<<endl;
}
