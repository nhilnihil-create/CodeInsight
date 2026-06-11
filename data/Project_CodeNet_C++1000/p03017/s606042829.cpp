#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if(a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if(b<a) { a=b; return 1; } return 0; }

int main(){
  int n,a,b,c,d; cin >> n >> a >> b >> c >> d;
  string s; cin >> s;
  a--; b--; c--; d--;
  bool ok = true;
  if(d < c){
    ok = false;
    for(int i = b-1; i <= d-1; i++) if(s.substr(i,3) == "...") ok = true;
  }
  bool ans = true;
  for(int i = a; i < max(c,d); i++) if(s.substr(i,2) == "##") ans = false;
  cout << (ok && ans ? "Yes" : "No");
  cout << "\n";
  return 0;
}
