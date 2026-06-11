#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main(){
  ll ans = 0,N;
  cin >> N;
  string S; cin >> S;
  rep(i,S.size()-2){
    if(S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C'){
      ans++;
    }
  }
  cout << ans;
}