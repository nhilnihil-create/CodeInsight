#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int N,K;
  ll S;
  cin >> N >> K >> S;
  
  vector<ll> v(N);
  for(int i = 0; i < K; i++){
    v[i] = S;
  }
  for(int i = K; i < N; i++){
    if(S == 1000000000){
      v[i] = 1;
    } else { 
      v[i] = S+1;
    }
  }
  for(int i = 0; i < N; i++){
    if(i == N-1){
      cout << v[i] << endl;
    } else { 
      cout << v[i] << " ";
    }
  }
}