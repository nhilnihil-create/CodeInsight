#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,M,X;
  cin>>N>>M>>X;
  vector<long long>C(N);
  vector<vector<long long>>A(N,vector<long long>(M));
  long long ans=100000000;
  for(long long i=0;i<N;i++){
    cin>>C.at(i);
    for(long long j=0;j<M;j++){
      cin>>A.at(i).at(j);
    }
  }
  for(long long i=0;i<1<<N;i++){
    vector<long long>test(M);
    long long sum=0;
    bool test2=true;
    for(long long j=0;j<N;j++){
      if(i>>j&1){
        sum+=C.at(j);
      for(long long k=0;k<M;k++){
        test.at(k)+=A.at(j).at(k);
      }
      }
    }
    for(long long m=0;m<M;m++){
      if(test.at(m)<X){
        test2=false;
      }
    }
    if(test2){
      ans=min(sum,ans);
    }
  }
  if(ans==100000000){
    cout<<"-1"<< endl;
    return 0;
  }
  else{
    cout<<ans<< endl;
    return 0;
  }
}
  