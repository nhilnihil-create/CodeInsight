#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  string S; cin >> S;
  bool a = true;
  for(ll i = 0; i < S.size();i += 2){
    if(S[i] == 'L'){
      a = false;
    }
  }
  for(ll i = 1; i < S.size();i += 2){
    if(S[i] == 'R'){
      a = false;
    }
  }
  if(a){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}