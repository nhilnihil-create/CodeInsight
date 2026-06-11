#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MOD 1000000007

int main(){
  ll N,K;
  cin>>N>>K;
  vector<ll> A(N);
  for(int i=0;i<N;i++){
    cin>>A.at(i);
  }

  ll ans=0;
  vector<ll> count(N,0);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(A.at(i)>A.at(j)){
        count.at(i)++;
        if(i<j){
          ans++;
        }
      }
    }
  }
  ans%=MOD;
  ans*=K;
  ans%=MOD;

  for(int i=0;i<N;i++){
    ans+=(K*(K-1)/2%MOD)*(ll)count.at(i);
    ans%=MOD;
  }

  cout<<ans<<endl;
}
