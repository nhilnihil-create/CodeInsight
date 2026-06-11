#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), V(N,0);
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }
  for (int i=0; i<N; i++) {
    V[A[i]-1]++;
  }
  
  ll S=0;
  for (int i=0; i<N; i++) {
    ll m;
    if (V[i]*(V[i]-1)/2>0) {m=V[i]*(V[i]-1)/2;}
    else {m=0;}
    S+=m;
  }
  //cout << S << endl;
  for (int i=0; i<N; i++) {
    ll m;
    m=V[A[i]-1]-1;
    cout << S-m << endl;
  }
}
