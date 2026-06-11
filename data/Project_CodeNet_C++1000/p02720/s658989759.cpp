#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int k; cin >> k;
  queue<ll> q;
  rep(i,9) q.push(i+1);
  rep(i,k){
    ll x = q.front(); q.pop();
    if(x % 10 != 0) q.push(10*x+x%10-1);
    q.push(10*x+x%10);
    if(x % 10 != 9) q.push(10*x+x%10+1);
    if(i == k-1){
      cout << x;
      return 0;
    }
  }
  cout << "\n";
  return 0;
}
