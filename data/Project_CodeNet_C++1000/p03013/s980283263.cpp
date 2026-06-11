#include <bits/stdc++.h>
using namespace std;
long long INF=1e9+7;
int main(){
  int N,K; cin>>N>>K;
  vector<long long>A(K);
  vector<long long>count(100001);
  count[0]=1;
  count[1]=1;
  for(int i=2;i<100001;i++){count[i]=count[i-1]+count[i-2];count[i]%=INF;}
  for(int i=0;i<K;i++){
    cin>>A[i];
    if(i!=0)if(A[i]-1==A[i-1]){cout<<0<<endl; return 0;}
  }
  if(K==0){
    cout<<count[N]<<endl;
    return 0;
  }
  long long ans=1;
  for(int i=0;i<=K;i++){
    if(i==0)ans*=count[A[i]-1];
    else if(i==K)ans*=count[N-A[i-1]-1];
    else ans*=count[A[i]-A[i-1]-2];
    ans%=INF;
  }
  cout<<ans<<endl;
}