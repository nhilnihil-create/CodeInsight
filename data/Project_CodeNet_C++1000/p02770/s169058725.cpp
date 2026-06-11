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
ll nextLong() { ll x; scanf("%lld", &x); return x;}

int main2() {
  int K = nextInt();
  int Q = nextInt();
  vector<int> D(K);
  REP(i, K) D[i] = nextInt();

  vector<int> d(K);
  REP(qi, Q) {
    ll N = nextInt();
    ll X = nextInt();
    ll M = nextInt();
    REP(i, K) d[i] = D[i] % M;

    ll N1 = N - 1;
    ll Y = X;
    REP(i, K) {
      Y += d[i] * (N1 / K);
      if (i < N1 % K) Y += d[i];
    }
    int c = (Y/M) - (X/M);
    int zero = 0;
    REP(i, K) if (d[i] == 0) {
      zero += N1 / K;
      zero += (i < N1 % K) ? 1 : 0;
    }
    ll ans = N1 - zero - c;
    printf("%d\n", (int)ans);
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