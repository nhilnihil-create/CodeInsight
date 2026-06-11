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
  int k; cin >> k;
  int ans = 0;
  rep(a,k) rep(b,k) rep(c,k) ans += gcd(a+1,gcd(b+1,c+1));
  cout << ans;
  cout << "\n";
  return 0;
}
