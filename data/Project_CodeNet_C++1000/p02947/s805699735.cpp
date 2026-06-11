#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  REP(i,n){
    cin >> s[i];
    sort(s[i].begin(),s[i].end());
  }
  sort(s.begin(),s.end());
  ll a = 1;
  ll ans = 0;
  REP(i,n){
    if(i != n-1){
      if(s[i] == s[i+1]){
        a++;
      }
      else{
        ans += a*(a-1)/2;
        a = 1;
      }
    }
  }
  ans += a*(a-1)/2;
  cout << ans << endl;
  

}