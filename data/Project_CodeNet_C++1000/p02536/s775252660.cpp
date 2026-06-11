#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);
struct UnionFind {
  vector< int > data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
 
  bool findSet(int x,int y){
    return find(x) == find(y);
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }
};

int main(void){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n,m;
  cin >> n >> m;
  UnionFind uni(n);
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    uni.unite(a,b);
  }
  set<int> st;
  rep(i,n){
    st.insert(uni.find(i));
  }
  cout << st.size() - 1 << endl;
}