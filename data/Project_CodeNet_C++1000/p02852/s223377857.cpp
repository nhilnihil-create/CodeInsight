#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1000000001;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;

  vector<int> ans;
  reverse(s.begin(), s.end());
  for(int i = 0; i < n;){
    int mx_j = 0;
    for(int j = 1; j <= m; ++j){
      if(i + j > n) continue;
      if(s[i + j] == '0'){
        mx_j = j;
      }
    }
    if(mx_j == 0){
      cout << -1 << endl;
      return 0;
    }
    i += mx_j;
    ans.push_back(mx_j);
  }

  reverse(ans.begin(), ans.end());
  for(int i = 0; i < ans.size(); ++i){
    cout << ans[i] << " ";
  }
  cout << endl;
  return 0;
}
