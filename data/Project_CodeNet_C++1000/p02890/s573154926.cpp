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

int nextInt() { int x; scanf("%d", &x); return x;}

const int MAX_N = 312345;
int A[MAX_N];
int F[MAX_N];
ll memo[MAX_N];

int main2() {
  CLR(F, 0);
  CLR(memo, -1);

  int N = nextInt();
  REP(i, N) A[i] = nextInt();
  REP(i, N) F[A[i]]++;
  map<int, int> FC;
  REP(i, N+1) if (F[i] > 0) FC[ F[i] ]++;
  vector<pair<int,int>> F;
  for (auto it = FC.begin(); it != FC.end(); ++it) F.push_back({it->first, it->second});

  auto calc = [&](const int ans) -> ll {
    if (memo[ans] != -1) return memo[ans];
    ll res = 0;
    for (auto p : F) {
      res += min(p.first, ans) * p.second;
    }
    return memo[ans] = res;
  };

  for (int K = 1; K <= N; K++) {
    int hi = N / K + 1;
    int lo = 0;
    while (hi - lo > 1) {
      int mid = (hi + lo) / 2;
      bool possible = (mid * (ll)K <= calc(mid));
      if (possible) { lo = mid; } else { hi = mid; }
    }
    int ans = lo;
    printf("%d\n", ans);
  }
  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
