#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
 int n,m;
  cin>>n>>m;
  vin a(n);
  rep(i,0,n) cin>>a[i];
  priority_queue<int> pq;
  rep(i,0,n) pq.push(a[i]);
  rep(i,0,m){
    int b=pq.top();  //最高価格
    b/=2;
    pq.pop();
    pq.push(b);
  }
  ll ans=0;
  rep(i,0,n){
   ans+=pq.top(); 
    pq.pop();
  }
  cout<<ans<<endl;
}

