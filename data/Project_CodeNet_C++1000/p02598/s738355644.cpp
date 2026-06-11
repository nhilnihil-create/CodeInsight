#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cuts(ll L,ll x){
  //minimum n s.t. L/n<=x
  int ans = (L-1)/x + 1;
  return ans-1;
}

int main(){
  int N;cin >> N;
  int K;cin >> K;
  vector<ll> A(N);
  ll Amax=0;
  for(int i=0;i<N;i++){
    cin >> A[i];
    Amax = max(Amax,A[i]);
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  ll U = 0,L = Amax;
  while(1<L-U){
    ll M = (U+L)/2;
    //cout << U << " " << M << " " << L;
    int cnt = 0;
    for(int i=0;i<N;i++){
      if(A[i]<=M){
        break;
      }else{
        cnt += cuts(A[i],M);
      }
    }
    //cout << " # " << cnt << endl;
    if(cnt>K){
      U = M;
    }else{
      L = M;
    }
  }
  //cout << U << " " <<  L << endl;
  cout << L << endl;
}