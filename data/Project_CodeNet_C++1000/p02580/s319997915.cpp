#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db; 
typedef string str;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
 
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(), x.end()
#define endl '\n'

const ll MOD = 1000000007;

int main() {
   int H, W, M; scanf("%d%d%d", &H, &W, &M);
   vector<int> rowCnt(H), colCnt(W);
   set<pi> m;
   for (int i = 0; i < M; i++) {
      int h, w; scanf("%d%d", &h, &w);
      m.insert({h - 1, w - 1});
      rowCnt[h - 1]++;
      colCnt[w - 1]++;
   }
   int maxRow = 0, maxCol = 0;
   for (int i : rowCnt)
      maxRow = max(maxRow, i);
   for (int i : colCnt)
      maxCol = max(maxCol, i);
   vector<int> maxRowIdx;
   for (int i = 0; i < H; i++)
      if (rowCnt[i] == maxRow) maxRowIdx.pb(i);
   vector<int> maxColIdx;
   for (int i = 0; i < W; i++)
      if (colCnt[i] == maxCol) maxColIdx.pb(i);
   int ans = maxRow + maxCol - 1;
   if (maxRowIdx.size() * maxColIdx.size() <= M) {
      for (int i : maxRowIdx) {
         for (int j : maxColIdx)
            if (m.find({i, j}) == m.end()) ans = maxRow + maxCol;
      }
   } else {
      ans += 1;
   }
   printf("%d", ans);
   return 0;
}