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


/**
 * 整数の集合 A と、整数 X が与えられる。
 * Aの部分集合 S に対して関数f(S)をSの全要素をexorした値と定義する。
 * X ^ f(S) の最大値を返す
 */
ll maxSubsetExor(vector<ll> A, ll X) {

  const int N = A.size();
  const int M = 62;

  auto at = [&](const ll Ai, const int j) -> int {
    return (Ai >> (M-j-1) & 1);
  };


  int s = 0;
  REP(j, M) {
    int p = -1;
    for (int i = s; i < N; i++) if (at(A[i], j)) { p = i; break; }
    if (p != -1) {
      swap(A[s], A[p]);
      for (int i = s+1; i < N; i++) if (at(A[i], j)) A[i] ^= A[s];
      s++;
    }
  }

  ll ans = X;
  s = 0;
  REP(j, M) {
    if (at(ans, j) == 0 && at(A[s], j)) ans ^= A[s];
    if (at(A[s], j)) s++;
  }

  return ans;
}

int main2() {
  int N; cin >> N;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];

  ll S = 0;
  REP(i, N) S ^= A[i];

  REP(i, N) A[i] &= ~S;

  ll P = maxSubsetExor(A, 0);
  ll Q = S ^ P;

  cout << P + Q << endl;

  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}
