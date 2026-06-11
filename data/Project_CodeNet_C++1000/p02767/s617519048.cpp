#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  ll sum;
  vector<ll> X(N);
  for(ll i=0;i<N;i++){
    cin >> X.at(i);
    sum += X.at(i);
  }
  ll ave1,ave2;
  ave1=sum/N;
  ave2=sum/N+1;
  ll V1=0;
  ll V2=0;
  for(ll i=0;i<N;i++){
    V1 = V1 + (X.at(i)-ave1)*(X.at(i)-ave1);
    V2 = V2 + (X.at(i)-ave2)*(X.at(i)-ave2);
  }
  cout << min(V1,V2) << endl;
}
