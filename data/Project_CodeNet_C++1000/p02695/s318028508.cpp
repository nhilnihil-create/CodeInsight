#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

struct Que {
  int a,b,c,d;
  //  Que(int a,int b,int c, int d) : a(a), b(b), c(c), d(d) {}
};

int main() {
  int N, M, Q;cin >> N >> M >> Q;
  vector<Que> query(Q);
  rep(i,Q) {
    int a, b, c, d;cin >> a >> b >> c >> d;
    a--;b--;
    query[i].a = a;
    query[i].b = b;
    query[i].c = c;
    query[i].d = d;    
  }
  queue<string> qu;
  qu.push("1");
  int ans = 0;
  while(!qu.empty()) {
    string now = qu.front();
    // cout << now << endl;
    qu.pop();
    int siz = now.size();
    if(siz == N) {
      int sum = 0;
      for (auto q : query) {
	if(now[q.b] - now[q.a] == q.c) {
	  sum += q.d;
	}
      }
      ans = max(ans, sum);
      continue;
    }
    int last = now[siz - 1] - '0';
    for (int add = last; add <= M ; add++) {
      string nxt = now;
      nxt += add + '0';
      qu.push(nxt);
    }
  }
  cout << ans << endl;
}
