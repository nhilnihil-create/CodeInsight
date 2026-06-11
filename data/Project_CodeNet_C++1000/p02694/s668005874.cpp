#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  ll X;
  cin >> X;
  ll N = 100;
  int C=0;
  if(N==X){
    cout << 0 << endl;
    return 0;
  }
  while(N<X){
    N += N/100;
    C++;
  }
  cout << C << endl;
}