#include<bits/stdc++.h>
using namespace std;

int main(){
  const long M=1e18;
  int N;cin>>N;
  vector<long> A(N);
  for(int i=0;i<N;i++) cin>>A.at(i);
  sort(A.begin(),A.end());
  long ans=1;
  for(int i=0;i<N;i++){
    if(A.at(i)==0){
      ans=0;
      break;
    }
    else if(M/ans+1<=A.at(i)){
      ans=-1;
      break;
    }
    else ans*=A.at(i);
  }
  cout<<ans<<endl;
}
  