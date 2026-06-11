#include <bits/stdc++.h>
using namespace std;

using int32 = int_fast32_t;
using int64 = int_fast64_t;

const int32 INF = 1e9;
const int32 MOD = 1e9+7;
const int64 LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES\n" : "NO\n"  )
#define Yes(n) cout << ((n) ? "Yes\n" : "No\n"  )
#define POSSIBLE cout << ((n) ? "POSSIBLE\n" : "IMPOSSIBLE\n"  )
#define ANS(n) cout << (n) << "\n"
#define REP(i,n) for(int64 i=0;i<(n);++i)
#define FOR(i,a,b) for(int64 i=(a);i<(b);i++)
#define FORR(i,a,b) for(int64 i=(a);i>=(b);i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define pii pair<int32,int32>
#define pll pair<int64,int64>
#define pb(a) push_back(a)

#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct FenwickTree{
    vector<T> fenwick;
    int  n;

    FenwickTree(int n):
        fenwick(vector<T>(n+1, 0)), n(n) {}

    T sum(int i) {
        if (!i) return 0;
        return fenwick[i] + sum(i-(i&-i));
    }

    T sum(int i, int j){
        // half-open Terval
        return sum(j-1) - sum(i-1);
    }

    void add(int i, T x) {
        if (i > n) return;
        fenwick[i] += x;
        add(i+(i&-i), x);
    }
};

//1-indexed
//  http://na-o-s.hateblo.jp/entry/2014/07/13/031143

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int32 n,d,a;
  cin >> n >> d >> a;
  vector<pii> xh(n);
  REP(i,n){
    cin >> xh[i].first >> xh[i].second;
    xh[i].second = (xh[i].second + a - 1) / a;
  }
  sort(ALL(xh));
  FenwickTree<int32> ft(n);
  int64 ans = 0;
  REP(i,n){
    int32 l = lower_bound(ALL(xh), pii(xh[i].first-2*d,-INF)) - xh.begin();
    xh[i].second = max<int32>(0, xh[i].second - ft.sum(l+1,i+2));
    ans += xh[i].second;
    ft.add(i+1,xh[i].second);
  }
  ANS(ans);
  return 0;
}