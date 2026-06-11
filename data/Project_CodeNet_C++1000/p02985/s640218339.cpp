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

const ll MOD = 1000000007;

const int MAX_N = 112345;
vector<int> g[MAX_N];

ll ans;
ll K;
void dfs(int cur, int prev, ll kk) {
  (ans *= kk) %= MOD;
  int ci = 0;
  for (int nxt : g[cur]) if (nxt != prev) {
    dfs(nxt, cur, K - 1 - ci - (prev != -1 ? 1 : 0));
    ci++;
  }
}


int main2() {
  REP(i, MAX_N) g[i].clear();
  int N = nextLong();
  K = nextLong();
  REP(i, N-1) {
    int a = nextLong()-1;
    int b = nextLong()-1;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  ans = 1;
  dfs(0, -1, K);
  cout << ans << endl;
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}