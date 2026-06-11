#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  ll A,B,N;
  cin >> A >> B >> N;
  ll x;
  if(N<B-1) x=N;
  else x=B-1;
  ll M = (A*x-(A*x%B))/B-A*((x-x%B)/B);
  cout << M << endl;
}