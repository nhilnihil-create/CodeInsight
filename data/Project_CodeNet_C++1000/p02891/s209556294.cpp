#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF 1e9
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  string s; cin >> s;
  int n = s.size();
  int k; cin >> k;
  ll ans = 0;
  bool same = true;

  rep(i,n-1){
    if(s[i] == s[i+1]){
      ans++;
      i++;
    }
    if(s[0] != s[i+1]) same = false;
  }

  if(same){
    ans = (ll)n*k/2;
  }else{
    ans *= k;
    if(s[0] == s[n-1]){
      int a = 0, b = n-1;
      while(s[0] == s[a]) a++;
      while(s[n-1] == s[b]) b--;
      b = n-1 - b;
      ans -= (a/2 + b/2 - (a+b)/2)*(k-1);
    }
  }

  cout << ans;
  cout << "\n";
  return 0;
}
