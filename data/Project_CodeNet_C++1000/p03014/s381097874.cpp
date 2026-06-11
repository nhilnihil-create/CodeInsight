#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); i++)
#define rrep(i, a, b) for (int i = a; i >= (b); i--)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <class T>
inline bool chmin(T& a, T b) {
   if (a > b) {
      a = b;
      return true;
   }
   return false;
}
template <class T>
inline bool chmax(T& a, T b) {
   if (a < b) {
      a = b;
      return true;
   }
   return false;
}
void hr() {
   cerr << "--------------" << endl;
}
const int INF = 1001001001;
const int MOD = 1000000007;

int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int h, w;
   cin >> h >> w;
   vector<string> s(h);
   rep(i, 0, h) cin >> s[i];

   vector<vector<int>> cnt(h, vector<int>(w));
   rep(i, 0, h) {
      vector<bool> done(w, false);
      rep(j, 0, w) {
         if (done[j]) continue;
         if (s[i][j] == '#') continue;
         int l = 0;
         while (j + l < w) {
            if (s[i][j + l] == '#') break;
            l++;
         }
         rep(k, 0, l) {
            cnt[i][j + k] += l;
            done[j + k] = true;
         }
      }
   }

   rep(j, 0, w) {
      vector<bool> done(h, false);
      rep(i, 0, h) {
         if (done[i]) continue;
         if (s[i][j] == '#') continue;
         int l = 0;
         while (i + l < h) {
            if (s[i + l][j] == '#') break;
            l++;
         }
         rep(k, 0, l) {
            cnt[i + k][j] += l;
            done[i + k] = true;
         }
      }
   }

   int ans = 0;
   rep(i, 0, h) rep(j, 0, w) ans = max(ans, cnt[i][j] - 1);
   cout << ans << endl;
   return 0;
}