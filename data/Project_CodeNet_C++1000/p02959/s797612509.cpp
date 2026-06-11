#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>A(N+1);
  for(int i=0;i<N+1;i++){
    cin>>A.at(i);
  }
  vector<int>B(N);
  for(int i=0;i<N;i++){
    cin>>B.at(i);
  }
  int64_t ans=0;
  for(int i=0;i<N;i++){
    if(A.at(i)<B.at(i)&&A.at(i)+A.at(i+1)>=B.at(i)){
      ans+=B.at(i);
      A.at(i+1)=A.at(i+1)-B.at(i)+A.at(i);
    }
    else if(A.at(i)<B.at(i)&&A.at(i)+A.at(i+1)<B.at(i)){
      ans+=A.at(i)+A.at(i+1);
      A.at(i+1)=0;
    }
    else if(A.at(i)==B.at(i)){
      ans+=A.at(i);
    }
    else if(A.at(i)>B.at(i)){
      ans+=B.at(i);
    }
  }
  cout<<ans<<endl;
}
