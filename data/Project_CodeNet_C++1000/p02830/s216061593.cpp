#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  ll A;
  string S,T;
  cin >> A >> S >> T;
  rep(i,A){
    cout << S[i] << T[i];
  }
}