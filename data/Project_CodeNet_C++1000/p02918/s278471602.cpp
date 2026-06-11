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
  int n,k; cin >> n >> k;
  string s; cin >> s;
  vi cnt;
  char a = s[0];
  int num = 0;
  rep(i,n){
    if(a != s[i]){
      cnt.push_back(num);
      num = 0;
      a = s[i];
    }
    num++;
  }
  cnt.push_back(num);
  rep(i,cnt.size()-1){
    if(i < 2*k){
      cnt[i+1] += cnt[i];
      cnt[i] = 1;
    }
  }
  int ans = 0;
  rep(i,cnt.size()) ans += cnt[i]-1;
  cout << ans;
  cout << "\n";
  return 0;
}
