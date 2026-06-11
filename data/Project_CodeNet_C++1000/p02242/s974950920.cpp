#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define vvi vector<vector<int>>
#define vec vector
#define pq priority_queue
#define all(v) (v).begin(), (v).end()
#define uniqueV(x) sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());
#define rep(i, n) for (int (i) = (0); (i) < (n); ++(i))
#define repp(i, m, n) for (int (i) = (m); (i) < (n); ++(i))
#define debug(x) cerr << #x << ": " << x << endl;
#define debug2(x, y) cerr<<"("<<#x<<", "<<#y<<") = "<<"("<<x<<", "<<y<<")"<<endl;
#define debug3(x, y, z) cerr<<"("<<#x<<", "<<#y<<", "<<#z<<") = "<<"("<<x<<", "<<y<<", "<<z<<")"<<endl;
#define debugB(x, y) cerr<<#x<<": "<<bitset<y>(x) << endl;
#define line() cerr << "---------------" << endl;
 
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const double PI = 3.14159265358979323846;
 
template<typename T>
void printA(vector<T> &printArray, char between = ' ') {
   int paSize = printArray.size();
   for (int i = 0; i < paSize; i++) { cerr << printArray[i] << between;}
   if (between != '\n') {cerr << endl;}
}
 
// ------------------------------------------------------------------------------------------
 
struct edge { int to, cost; };
struct P { 
   int dist, number; 
   bool operator<(const P &p) const {
      return dist < p.dist;
   }
   bool operator>(const P &p) const {
      return dist > p.dist;
   }
};
 
const int INF = 1e8;
int n;
vec<vec<edge>> G;
int d[111];

void printDist() {
   rep (i, n) { printf("%d %d\n", i, d[i]); }
}
 
void dijkstra(int s) {
   fill(d, d + n, INF);
   d[s] = 0;
   priority_queue<P, vec<P>, greater<P>> Q;
   Q.push({0, s});

   while (Q.size()) {
      P p = Q.top(); Q.pop();
      int v = p.number;
      if (d[v] < p.dist) continue;
      for (int i = 0; i < G[v].size(); i++) {
         edge e = G[v][i];
         if (d[e.to] > d[v] + e.cost) {
            d[e.to] = d[v] + e.cost;
            Q.push({d[e.to], e.to});
         }
      }
   }
}
 
int main() {
   // 入力
   cin >> n;
   G = vec<vec<edge>>(n);
   rep (i, n) {
      int u, k;
      cin >> u >> k;
      rep (j, k) {
         int v, c;
         cin >> v >> c;
         G[u].push_back({v, c});
      }
   }
 
   // ダイクストラ法
   dijkstra(0);
 
   // 出力
   printDist();
 
   return 0;
}
