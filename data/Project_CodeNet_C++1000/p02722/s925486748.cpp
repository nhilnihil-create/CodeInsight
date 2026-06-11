#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()


int main(){
  ll N,M,sum=0;
  cin >> N;
  for(ll i=2;i*i<=N;i++){
    M=N;
    while(M%i==0){
      M /= i;
    }
    if(M%i==1){
      sum++;
    }
    if(N%i==1){
      sum++;
    }
    if(N==i*i+1){
      sum--;
    }
  }
  sum += 2;
  if(N==2){sum=1;}
  cout << sum << endl;
}

  