#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  ll N = 0;
  string S;
  cin >> N >> S;
  rep(i,S.size()){
    char x = S[i];
    int check = x;
    if(check + N > 90){
      x = S[i]+N-26;
      cout << x;
    }
    else{
      x = S[i] + N;
      cout << x;
    }
  }
}