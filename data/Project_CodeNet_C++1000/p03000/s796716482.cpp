#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,X;
  cin>>N>>X;
  vector<int>D(N+1);
  D.at(0)=0;
  for(int i=0;i<N;i++){
    int x;
    cin>>x;
    D.at(i+1)=D.at(i)+x;
  }
  int ans=0;
  for(int i=0;i<=N;i++){
    if(D.at(i)<=X){
      ans++;
    }
  }
  cout<<ans<<endl;
}
