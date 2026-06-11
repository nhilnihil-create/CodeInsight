#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,K;
  cin>>N>>K;
  vector<int>A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }
  int ans=0;
  for(int i=0;i<N;i++){
    if(A.at(i)>=K){
      ans++;
    }
  }
  cout<<ans<<endl;
}
