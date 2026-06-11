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
  int n,k; cin >> n >> k;
  int r,s,p; cin >> r >> s >> p;
  string t; cin >> t;
  int ans = 0;
  rep(i,n){
    if(t[i] == 'r'){
      ans += p;
      if(t[i+k] == 'r' && i+k < n) t[i+k] = '*';
    }
    if(t[i] == 's'){
      ans += r;
      if(t[i+k] == 's' && i+k < n) t[i+k] = '*';
    }
    if(t[i] == 'p'){
      ans += s;
      if(t[i+k] == 'p' && i+k < n) t[i+k] = '*';
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
