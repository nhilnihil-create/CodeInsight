#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  ll A,B,K;
  cin >> A >> B >> K;
  if(A + B <= K){
    cout << "0 0";
    return 0;
  }
  if(A >= K){
    cout << A-K << " " << B;
  }
  else{
    cout << "0 " << A+B-K;
  }
}