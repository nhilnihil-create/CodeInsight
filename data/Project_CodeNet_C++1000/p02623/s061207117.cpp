#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N,M;cin >> N >> M;
  ll K;cin >> K;
  vector<ll> A(N+1,0);
  vector<ll> B(M+1,0);
  for(int i=0;i<N;i++){
    ll a;cin >> a;
    A[i+1] = A[i] + a;
  }
  for(int i=0;i<M;i++){
    ll b;cin >> b;
    B[i+1] = B[i] + b;
  }
  int X=0,Y=0;
  for(int i=0;i<=N;i++){
    if(A[i]<=K){
      X = i;
    }else{
      break;
    }
  }
  for(int i=0;i<=M;i++){
    if(A[X]+B[i]<=K){
      Y = i;
    }else{
      break;
    }
  }
  int sum = X + Y;
  while(X>=0){
    for(int i=Y;i<=M;i++){
      if(A[X]+B[i]<=K){
        Y = i;
      }else{
        break;
      }
    }
    sum = max(sum,X+Y);
    X --;
  }
  cout << sum << endl;
}