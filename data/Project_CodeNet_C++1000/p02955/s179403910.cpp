#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N,K;
  cin>>N>>K;
  vector<int64_t>A(N);
  int64_t sum=0;
  for(int i=0;i<N;i++){
  cin>>A.at(i); sum+=A.at(i);
  }
  vector<int64_t>C;
  for(int64_t i=1;i*i<=sum;i++)
    if(sum%i==0)C.push_back(i);
  int64_t M=C.size();
  for(int64_t i=0;i<M;i++)
    C.push_back(sum/C[M-1-i]);
  vector<int64_t>D(N,0);
  int64_t ans=-1;
  for(int i=2*M-1;0<=i;i--){
   int64_t sum1=0;int64_t a=C[i];
    for(int j=0;j<N;j++){
    D.at(j)=A[j]%a; sum1+=D.at(j);
    }sum1/=a;
    sort(D.begin(),D.end());int64_t x=0;
    for(int j=0;j<N-sum1;j++)
      x+=D.at(j);
    if(x<=K){ans=a;break;}
  }cout<<ans<<endl;
    
  return 0;
}