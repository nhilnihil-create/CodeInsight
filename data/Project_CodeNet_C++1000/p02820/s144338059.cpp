#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;

    

int main(){
  ll N,K,R,S,P,ans=0;
  string T;
  cin >> N >> K >> R >> S >> P >> T;
  rep(i,K){
    ll j=0;
    while(i+j*K<N){
      if(T.at(i+j*K)=='r'){
        ans+=P;
      }else if(T.at(i+j*K)=='s'){
        ans+=R;
      }else{
        ans+=S;
      }
      if(i+(j+1)*K<N){
        if(T.at(i+j*K)==T.at(i+(j+1)*K)){
          j++;
        }
      }
      j++;
    }
  }
  cout << ans << endl;
         
        
    
  
}
