#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  ll N,K; cin >> N >> K;
  if(N % (2*K + 1) != 0){
    cout << N/(2*K + 1) + 1;
  }
  else{
    cout << N/(2*K + 1);
  }
}
  