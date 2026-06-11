#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N,K;
  cin >>N>>K;
  ll a,b,c;
  cin >>a>>b>>c;
  string T;
  cin >> T;
  ll ans=0;
  for(int i=0;i<N;i++){
    if(i<K){
      if(T[i]=='r'){
        ans+=c;
        continue;
      }
      if(T[i]=='s'){
        ans+=a;
        continue;
      }
      if(T[i]=='p'){
        ans+=b;
        continue;
      }
    }
    else{
      if(T[i]==T[i-K]){
        T[i]='o';
        continue;
      }
      else{
        if(T[i]=='r'){
          ans+=c;
          continue;
        }
        if(T[i]=='s'){
          ans+=a;
          continue;
        }
        if(T[i]=='p'){
          ans+=b;
          continue;
        }
      }
    }
  }
  cout << ans <<endl;
}
    