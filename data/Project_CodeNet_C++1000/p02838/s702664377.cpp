#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  int64_t ans=0;
  for(int i=0;i<N;i++)
    ans=(ans+A.at(i))%mod;
  ans=((N-1)*ans)%mod;
  vector<int64_t>B(61,0);
  for(int i=0;i<N;i++){
  int64_t b=A.at(i);
    for(int j=0;j<=60;j++){
    if(b%2==1)
      B.at(j)++;
      b/=2;
    }
  }int64_t ans1=0;
  for(int i=0;i<=60;i++){
  int64_t k=((B.at(i)*(B.at(i)-1))/2)%mod;
    int64_t m=powl(2,i+1);
    ans1=(ans1+(m%mod)*k)%mod;
  }int64_t ans2=(mod+ans-ans1)%mod;
  cout<<ans2<<endl;
    return 0;
}