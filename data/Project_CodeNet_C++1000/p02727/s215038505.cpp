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

int main2() {
  ll X = nextLong();
  ll Y = nextLong();
  ll A = nextLong();
  ll B = nextLong();
  ll C = nextLong();
  vector<ll> p(A), q(B), r(C);
  REP(i, A) p[i] = nextLong();
  REP(i, B) q[i] = nextLong();
  REP(i, C) r[i] = nextLong();

  sort(ALL(p)); reverse(ALL(p));
  sort(ALL(q)); reverse(ALL(q));
  sort(ALL(r)); reverse(ALL(r));

  vector<ll> eat;
  REP(i, X) eat.push_back(p[i]);
  REP(i, Y) eat.push_back(q[i]);
  REP(i, r.size()) eat.push_back(r[i]);
  sort(ALL(eat)); reverse(ALL(eat));

  ll ans = 0;
  REP(i, X+Y) ans += eat[i];
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