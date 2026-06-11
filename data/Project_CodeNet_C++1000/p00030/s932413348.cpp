#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define rep(i, n, m) for (int (i) = (n); (i) < (m); ++(i))
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define debugB(x, y) cerr<<#x<<": "<<bitset<y>(x) << endl;
#define line() cerr << "---------------" << endl;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int f(int m) {
   int cnt = 0;
   while (m > 0) {
      if (m&1) cnt++;
      m/=2;
   }
   return cnt;
}

int main() {
   int n, s;
   vec<int> num;
   for (int i = 0; i <= 9; i++) num.push_back(i);

   while (cin >> n >> s, n) {
      int cnt = 0;
      for (int mask = 0; mask < (1<<10); mask++) {
         int sum = 0;
         if (f(mask) != n) continue;
         for (int i = 0; i < 10; i++) {
            if ((mask>>i)&1) {
               sum += num[i];
            }
         }
         if (sum == s) cnt++;
      }
      cout << cnt << endl;
   }

   return 0;
}
