#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int main(){
int N; int64_t K;
  cin>>N>>K;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  int64_t T=0;
  for(int i=1;i<=N-1;i++){
  for(int j=N-1;i<=j;j--){
  int64_t a=A.at(j);
    int64_t b=A.at(j-1);
 if(a<b){A.at(j)=b; A.at(j-1)=a; T++;}
 }
  }map<int64_t,int64_t>M;
  for(int i=0;i<N;i++){
  if(M.count(A.at(i)))
    M.at(A.at(i))++;
    else
      M[A.at(i)]=1;
  }int64_t c=(N*(N-1))/2;
  for(auto p:M){
  auto k=p.first;
    auto v=p.second;
    c-=(v*(v-1))/2;
 }  int64_t ans=((K*T)%mod+((((K*(K-1))/2)%mod)*c)%mod)%mod;
  cout<<ans<<endl;
   return 0;
}