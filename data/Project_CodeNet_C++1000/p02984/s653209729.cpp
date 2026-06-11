#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

int main(){
  int N;
  cin>>N;
  vi A2(2*N);
  int a;
  ll all = 0;
  for(int i=0; i<N; i++){
    cin>>a;
    all += a;
    A2[i] = A2[i+N] = a*2;
  }

  vector<ll> B(N);
  B[0] = all;
  for(int i=1; i<N; i+=2){
    B[0] -= A2[i];
  }
  for(int i=2; i<N; i+=2){
    B[i] = B[i-2] + A2[i-1] - A2[i-2+N];
  }

  B[1] = all;
  for(int i=2; i<N; i+=2){
    B[1] -= A2[i];
  }
  for(int i=3; i<N; i+=2){
    B[i] = B[i-2] + A2[i-1] - A2[i-2+N];
  }

  for(int x: B){
    cout<<x<<" ";
  }
  cout<<endl;
}