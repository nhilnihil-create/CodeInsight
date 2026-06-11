#include <bits/stdc++.h>

#ifndef LOCAL_
#define fprintf if( false ) fprintf
#endif // LOCAL_
// #define dump() fprintf(stderr, "#%s.%d\n", __func__, __LINE__);
#define dumpl(x1) fprintf(stderr, "#%s.%d (%s) = (%ld)\n", __func__, __LINE__, #x1, x1);
#define dumpll(x1, x2) fprintf(stderr, "#%s.%d (%s, %s) = (%ld, %ld)\n", __func__, __LINE__, #x1, #x2, x1, x2);
#define dumplll(x1, x2, x3) fprintf(stderr, "#%s.%d (%s, %s, %s) = (%ld, %ld, %ld)\n", __func__, __LINE__, #x1, #x2, #x3, x1, x2, x3);
#define dumpd(x1) fprintf(stderr, "#%s.%d (%s) = (%lf)\n", __func__, __LINE__, #x1, x1);
#define dumpdd(x1, x2) fprintf(stderr, "#%s.%d (%s, %s) = (%lf, %lf)\n", __func__, __LINE__, #x1, #x2, x1, x2);
#define loop for(;;)

template<typename T> void scan1(T& x) { fprintf(stderr, "unknown type\n"); }
template<> void scan1(long& x) { if( scanf("%ld", &x) < 0 ) exit(0); }
void scan() {}
template<typename Head, typename... Tail>
void scan(Head& x, Tail&... xs) {
  scan1(x); scan(xs...);
}

template<typename W>
struct N008 {
   typedef std::vector<long> LI;
   typedef std::vector<W>    LW;
   long n, e;
   const LI &ss, &ds;
   const LW &ws;
   std::vector<LI> fi;
   std::vector<LI> ri;
   N008(long n_, const LI& ss_, const LI& ds_, const LW& ws_)
      : n(n_), e(ss_.size()), ss(ss_), ds(ds_), ws(ws_) {
      ri.resize(n+1);
      fi.resize(n+1);
      for(long i = 0; i < e; ++i) {
         fi[ss[i]].push_back(i);
         ri[ds[i]].push_back(i);
      }
   }
};

template<typename W>
struct N010 {
   typedef std::vector<long> LI;
   const N008<W>& g;
   LI xs, ys;
   long id;
   N010(const N008<W>& g_) : g(g_), xs(g.n+1, -1), id(0) {
      for(long i = 0; i < g.n + 1; ++i) dfs(i);
      std::reverse(ys.begin(), ys.end());
   }
   void dfs(long t) {
      if( xs[t] != -1 ) return;
      for(long i : g.fi[t]) {
         long to = g.ds[i];
         dfs(to);
      }
      if( xs[t] == -1 ) xs[t] = id, id += 1, ys.push_back(t);
   }
};

struct Solver {
   Solver() { fprintf(stderr, "--------Solver begin--------\n"); }
   ~Solver() { fprintf(stderr, "--------Solver end--------\n"); }
   void solve() {
      long v, e;
      scan(v, e);
      std::vector<long> ss(e), ds(e), ws(e);
      for(long i = 0; i < e; ++i) {
         scan(ss[i], ds[i]);
      }
      N008<long> g(v, ss, ds, ws);
      N010<long> topsort(g);
      for(long y : topsort.ys) {
         if( y < v ) printf("%ld\n", y);
      }
   }
};

int main() {
  loop std::unique_ptr<Solver>(new Solver())->solve();
}