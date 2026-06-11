#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0,_n=(int)(n);i<_n;++i)
#define ALL(v) (v).begin(),(v).end()
#define CLR(t,v) memset(t,(v),sizeof(t))
template<class T1,class T2>ostream& operator<<(ostream& os,const pair<T1,T2>&a){return os<<"("<<a.first<<","<<a.second<< ")";}
template<class T>void pv(T a,T b){for(T i=a;i!=b;++i)cout<<(*i)<<" ";cout<<endl;}
template<class T>void chmin(T&a,const T&b){if(a>b)a=b;}
template<class T>void chmax(T&a,const T&b){if(a<b)a=b;}

ll nextLong() { ll x; scanf("%lld", &x); return x;}

const ll MOD = 1e9 + 7;

const int MAX_N = 112345;

vector<int> g[MAX_N];
ll K;

ll ans;

void dfs(int cur, int prev, int c, int depth) {

  if (depth == 0) {
    ans = ans * K % MOD;
  }
  if (depth == 1) {
    ans = ans * (K-1-c) % MOD;
  }
  if (depth >= 2) {
    ans = ans * (K-2-c) % MOD;
  }

  int nc = 0;
  for (int nxt : g[cur]) if (nxt != prev) {
    dfs(nxt, cur, nc, depth + 1);
    nc++;
  }
}

int main2() {
  int N = nextLong();
  K = nextLong();
  REP(i, N-1) {
    int a = nextLong() - 1;
    int b = nextLong() - 1;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  ans = 1;
  dfs(0, -1, 0, 0);
  cout << ans << endl;

  REP(i, N) g[i].clear();

  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}