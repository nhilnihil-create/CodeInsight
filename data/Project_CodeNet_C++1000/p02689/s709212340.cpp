#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N,M;
  cin >> N >> M;
  vector<long long>V(N);
  for(long long i=0; i<N; i++){
    cin >> V[i];
  }
  vector<bool>vec(N,true);
  for(long long i=0; i<M; i++){
    long long A,B;
    cin >> A >> B;
    A--;B--;
    if(V[A] == V[B]){
      vec[A] = false;
      vec[B] = false;
    }
    else if(V[A] < V[B]){
      vec[A] = false;
    }
    else{
      vec[B] = false;
    }
  }
  long long ans = 0;
  for(long long i=0; i<N; i++){
    if(vec[i]){
      ans++;
    }
  }
cout << ans << endl;
}
