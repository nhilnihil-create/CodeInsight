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
// const int MOD = 998244353;

int main() {
   cin.tie(0);
   ios_base::sync_with_stdio(0);

   int n, k, c;
   cin >> n >> k >> c;
   string s;
   cin >> s;

   auto getPositions = [&]() {
      vector<int> res;
      for (int i = 0; i < n && res.size() < k;) {
         if (s[i] == 'o') {
            res.push_back(i);
            i += c + 1;
         } else {
            i++;
         }
      }
      return res;
   };
   vector<int> l, r;
   rep(ri, 0, 2) {
      if (ri == 0)
         l = getPositions();
      else {
         r = getPositions();
         rep(i, 0, k) r[i] = n - 1 - r[i];
      }
      reverse(s.begin(), s.end());
   }
   vector<int> lastL(n + 1, -1);
   rep(i, 0, k) lastL[l[i] + 1] = i;
   rep(i, 1, n) {
      if (lastL[i] == -1) lastL[i] = lastL[i - 1];
   }
   vector<int> lastR(n + 1, -1);
   rep(i, 0, k) lastR[r[i]] = i;
   rrep(i, n - 1, 0) {
      if (lastR[i] == -1) lastR[i] = lastR[i + 1];
   }
   rep(i, 0, n) {
      if (s[i] == 'x') continue;
      int li = lastL[i];
      int ri = lastR[i + 1];
      int cnt = 0;
      if (li != -1) cnt += li + 1;
      if (ri != -1) cnt += ri + 1;
      if (li != -1 && ri != -1 && r[ri] - l[li] <= c) cnt--;
      if (cnt >= k) continue;
      cout << i + 1 << endl;
   }
   return 0;
}