#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n;  cin >> n;
  vector<pair<int,int>> len(n);
  rep(i,n){
    int x,l; cin >> x >> l;
    len[i].first = x+l;
    len[i].second = x-l;
  }
  sort(all(len));
  int ans = 0, mn = -INF;
  rep(i,n){
    if(mn <= len[i].second){
      ans++;
      mn = len[i].first;
    }
  }
  cout << ans;
  cout << "\n";
  return 0;
}
