#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N,A,B;
  cin >> N >> A >> B;
  ll S;
  if(N%(A+B)<=A){
    cout << N/(A+B)*A+N%(A+B);
    return 0;
  }
  else if(N%(A+B)>A){
    cout << N/(A+B)*A+A;
    return 0;
  }
}