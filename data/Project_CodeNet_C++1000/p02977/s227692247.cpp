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

vector< pair<int,int> > ans;

bool solve(int N) {
  if (__builtin_popcount(N) == 1) return false;


  for (int p = 2; p + 1 <= N; p += 2) {
    ans.push_back({ N+p, N+p+1 });
    ans.push_back({ N+p+1, 1 });
    ans.push_back({ 1, p });
    ans.push_back({ p, p+1 });
  }
  ans.push_back({N+1, 3});


  if (N % 2 == 0) {
    int x = 1 << (31 - __builtin_clz(N ^ 1));
    int y = (N ^ 1) ^ x;

    if (x % 2) x += N;
    if (y % 2) y += N;
    ans.push_back({N,   x});
    ans.push_back({N+N, y});
  }

  return true;
}

int main2() {
  int N = nextLong();
  ans.clear();

  bool res = solve(N);
  if (res) {
    cout << "Yes" << endl;
    REP(i, ans.size()) {
      cout << ans[i].first << " " << ans[i].second << '\n';
    }
  } else {
    cout << "No" << endl;
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