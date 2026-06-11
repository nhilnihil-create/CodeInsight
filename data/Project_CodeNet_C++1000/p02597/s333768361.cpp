#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = n-1;
    int cnt = 0;
    while (l < r) {
      if (s[l] == 'W') {
        if (s[r] == 'W') r--;
        else {
          cnt++;
          l++; r--;
        }
      } else {
        if (s[l] == 'W') {
          l++; r--;
        } else {
          l++;
        }
      }      
    }
    cout << cnt << endl;
    return 0;
}