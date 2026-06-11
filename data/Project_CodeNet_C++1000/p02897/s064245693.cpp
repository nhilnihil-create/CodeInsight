#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int N = 0; cin >> N;
  if(N % 2 == 0){
    cout << "0.5000000000";
  }
  else{
    long double M = N;
    N += 1;
    N /= 2;
    cout << fixed << setprecision(10) << N/M;
  }
}