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
  int n,k,s; cin >> n >> k >> s;
  if(s < 1e9){
    rep(i,k) cout << s << " ";
    rep(i,n-k) cout << s+1 << " ";
  }else{
    rep(i,k) cout << s << " ";
    rep(i,n-k) cout << 1 << " ";
  }
  cout << "\n";
  return 0;
}
