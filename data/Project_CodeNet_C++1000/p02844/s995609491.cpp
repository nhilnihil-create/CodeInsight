#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  rep(i,1000){
    int check[3] = {i/100, i/10%10, i%10};
    bool ok[3] = {false};
    int k = 0;
    rep(j,n){
      if(s[j]-'0' == check[k]){
        ok[k] = true;
        k++;
      }
    }
    if(ok[0] && ok[1] && ok[2]) ans++;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
