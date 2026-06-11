#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= (b); --i)
#define trav(a, x) for(auto &a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;



int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;
  vector<pii> v(n);
  rep(i,0,n)
    cin >> v[i].first >> v[i].second;
  
  rep(i,1, n - 1) {
    if (v[i].first == v[i].second && v[i - 1].first == v[i - 1].second
        && v[i + 1].first == v[i + 1].second)
        {
          cout << "Yes";
          return 0;
        }
  }
  cout << "No";
}