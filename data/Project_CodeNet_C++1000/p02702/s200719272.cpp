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
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  const int m = 2019;
  string s; cin >> s;
  int n = s.size();
  vi num(n+1);
  reverse(all(s));
  int x = 1;
  rep(i,n){
    num[i+1] = (s[i]-'0')*x;
    x *= 10;
    x %= m;
  }
  rep(i,n){
    num[i+1] += num[i];
    num[i+1] %= m;
  }
  int ans = 0;
  vi cnt(m);
  rep(i,n+1) ans += cnt[num[i]]++;
  cout << ans;
  cout << "\n";
  return 0;
}
