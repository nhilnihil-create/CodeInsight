#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t N,K;cin>>N>>K;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  int64_t sum=0;
vector<int64_t>B(N);
  for(int i=0;i<N;i++){
  sum=(sum+A.at(i))%K;
    B.at(i)=sum-i;
  }int64_t ans=0;
  for(int i=0;i<N;i++)
    if(B.at(i)==1)ans++;
  map<int64_t,int64_t>M;
  for(int64_t i=0;i<N;i++){
    if(0<=i-K)
    M.at(B.at(i-K))--;
    if(M.count(B.at(i)))
      ans+=M.at(B.at(i));
    if(M.count(K+B.at(i)))
      ans+=M.at(K+B.at(i));
    if(M.count(B.at(i)))
       M.at(B.at(i))++;
       else
       M[B.at(i)]=1;
  }cout<<ans<<endl;
  
  return 0;
}