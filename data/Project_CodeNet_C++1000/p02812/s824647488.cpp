#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  rep(i,N-1){
      if(S.substr(i,3) == "ABC"){
          ans++;
      }
  }
  cout << ans << endl;



}