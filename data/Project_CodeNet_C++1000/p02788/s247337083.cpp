#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int INT_INF = 2147483647;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef pair<int,int> P;

int main(){
  int n,d,a;
  cin >> n >> d >> a;
  P m[n];
  rep(i,n){
    int x,h;
    cin >> x >> h;
    m[i]=P(x,h);
  }
  sort(m,m+n);
  ll totd = 0;
  ll ans = 0;
  queue<pair<ll,ll>> q;
  rep(i,n){
    while(q.size()>0&&q.front().first<m[i].first){
      //calculate totd to apply
      auto p = q.front();
      q.pop();
      totd -= p.second*a;
    }
    ll remain = m[i].second - totd;
    if(remain>0){
      ll c = (remain+a-1)/a;
      ans += c;
      totd += c*a;
      q.push(make_pair(m[i].first+2*d,c));
    }
  }
  cout << ans << endl;
}
