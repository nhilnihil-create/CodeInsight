#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  string S;
  cin >> S;
  ll A = S.size(),ans = 0;
  rep(i,A/2){
    if(S[i] != S[A-i-1]){
      ans++;
    }
  }
  cout << ans;
}