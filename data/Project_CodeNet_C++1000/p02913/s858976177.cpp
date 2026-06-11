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


using HashType = tuple<ll,ll>;
struct RollingHash {

  const ll mod1 = 999999893;
  const ll mod2 = 999999929;
  const ll b1 = 3422539;
  const ll b2 = 1245103;
  vector<ll> h1, h2;
  vector<ll> pow1, pow2;

  RollingHash(const string &s) {
    const int n = s.size();
    h1.assign(n+1, 0);
    h2.assign(n+1, 0);
    pow1.assign(n+1, 1);
    pow2.assign(n+1, 1);
    REP(i, n) {
      h1[i+1] = (h1[i] * b1 + s[i]) % mod1;
      h2[i+1] = (h2[i] * b2 + s[i]) % mod2;
      pow1[i+1] = pow1[i] * b1 % mod1;
      pow2[i+1] = pow2[i] * b2 % mod2;
    }
  }

  HashType get(int l, int r) {
    ll v1 = ((h1[r] - h1[l] * pow1[r-l]) % mod1 + mod1) % mod1;
    ll v2 = ((h2[r] - h2[l] * pow2[r-l]) % mod2 + mod2) % mod2;
    return HashType {v1, v2};
  }
};



int main2() {
  int N; cin >> N;
  string s; cin >> s;
  RollingHash h = RollingHash(s);

  int len = N/2;
  for (; len > 0 ; len--) {

    set<HashType> vis;

    bool found = false;
    for (int i = len; i + len <= N; i++) {
      vis.insert(h.get(i-len, i));
      if (vis.count(h.get(i, i + len)) > 0) {
        found = true;
        break;
      }
    }
    if (found) break;
  }
  cout << len << endl;

  return 0;
}

int main() {

#ifdef LOCAL
  for (;!cin.eof();cin>>ws)
#endif
    main2();
  return 0;
}