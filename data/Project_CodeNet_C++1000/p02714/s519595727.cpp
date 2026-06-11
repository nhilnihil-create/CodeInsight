#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  vector<int> r;
  vector<int> g;
  vector<int> b;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      r.push_back(i);
    }
    if (s[i] == 'G') {
      g.push_back(i);
    }
    if (s[i] == 'B') {
      b.push_back(i);
    }
  }
  ll count = r.size() * g.size() * b.size();
  char j;
  for (int i = 0; i < n-2; i++) {
    char o = s[i];
    for (int j = i+1; j < n-1; j++) {
      char t = s[j];
      if (o != t) {
        if (o == 'R' || t == 'R') {
          if (o == 'G' || t == 'G') {
            //j = 'b';
            auto itr = find(b.begin(), b.end(), (2*j-i));
            if (itr != b.end()) {
              count--;
            }
          }
          else {
            auto itr = find(g.begin(), g.end(), (2*j-i));
            if (itr != g.end()) {
              count--;
            }
          }
        }
        else {
          //j = 'r';
            auto itr = find(r.begin(), r.end(), (2*j-i));
            if (itr != r.end()) {
              count--;
            }
        }
      }
    }
  }
  cout << count << '\n';
}