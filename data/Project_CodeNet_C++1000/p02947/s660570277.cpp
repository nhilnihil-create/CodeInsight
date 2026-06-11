#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  map<string, int> S;
  rep(i,n){
    string s;
    cin >> s;
    
    sort(s.begin(), s.end());
    
    if(S.count(s)){
      ans = ans + S[s];
      S[s] = S[s] + 1;
    }
    else{
     S[s] = 1;  
    }
    
  }
 cout << ans;
  
  return 0;
}