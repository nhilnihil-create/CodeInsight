#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int INF = 1001001001;
const int MOD = 1e9+7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,k; cin >> n >> k;
  vi a(n); rep(i,n) cin >> a[i];
  int l = 0, r = INF;
  while(1 < r-l){
    int mid = (l+r)/2;
    auto f = [&](int x){
      ll cnt = 0;
      rep(i,n) cnt += (a[i]-1)/x;
      return cnt <= k;
    };
    if(f(mid)) r = mid;
    else l = mid;
  }
  cout << r;
  return 0;
}
