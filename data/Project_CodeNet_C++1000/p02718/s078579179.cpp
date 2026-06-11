#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M,ans=0;
  float Asum=0.0;
  cin>>N>>M;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
    Asum+=A.at(i);
  }

  for(int i=0;i<N;i++){
    if(A.at(i)>=Asum/M/4)ans++;
    //cout<<A.at(i)<<" "<<Asum/M/4<<endl;
  }
  
  //cout<<ans<<endl;
  
  if(ans>=M)cout<<"Yes";
  else cout<<"No";
  
}
