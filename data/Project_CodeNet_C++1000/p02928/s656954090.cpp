#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define adrep(i,s,n) for (int i=(s);i<(n);i++)
using namespace std;
typedef long long ll;

ll MOD=ll(1e9)+7;

int main(){

  ll N,K;
  cin>>N>>K;
  
  ll A[N];
  rep(i,N){
    cin>>A[i];
  }
  ll count=0;
  ll count2=0;
  
  rep(i,N-1){
  for(int j=i+1;j<N;j++){

      if( A[i]>A[j] )count++;

      if( A[j]>A[i] )count2++;
               
    }
  }

  if(K==1){cout<<count<<endl;return 0;}
  ll ans=(K*(K+1)/2%MOD*count+(K-1)*K/2%MOD*count2%MOD)%MOD;
 
  cout<<ans<<endl;
}