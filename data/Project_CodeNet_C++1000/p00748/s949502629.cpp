#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)
#define Rep(i,n) for(int i=1;i<=n;++i)
#define rrep(i,n) for(int i=n-1;0<=i;--i)
#define rRep(i,n) for(int i=n;0<i;--i)
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define EPS 1e-8
#define INF 1e8

typedef double Real;
typedef int Int;
typedef vector<Int> vi;
typedef vector<vector<Int> > vvi;
typedef pair<Int,Int> pii;

inline Real sr(Real a) {return sqrt(max(a, (Real)0));}
const vi dy = {-1, 0, 1, 0}, dx = {0, -1, 0, 1};

template <typename K, typename V> ostream& operator<< (ostream& out, const pair<K, V>& p) {
  out << '(' << p.first << ", " << p.second << ')';
  return out;
}

template <typename T> ostream& operator<< (ostream& out, const vector<T>& v) {
  out << '[';
  rep(i, v.size()) out << v[i] << ",";
  out << "\b], " << v.size();
  return out;
}

vi tetrahedralNums;

inline int calcTetrahedralNum(int N){
  return N * (N + 1) * (N + 2) / 6;
}

int M = 183;

void solve(){
  int N, ansA, ansB;
  tetrahedralNums.resize(M);
  rep(i, M) tetrahedralNums[i] = calcTetrahedralNum(i+1);

  vi dp1(1e6+1, INF), dp2(1e6+1, INF);
  dp1[0] = 0;
  rep(i, M){
    int m = tetrahedralNums[i];
    for(int j = m; j <= 1e6; j++)
      if(dp1[j] > dp1[j - m] + 1)
          dp1[j] = dp1[j - m] + 1;
  }

  dp2[0] = 0;
  rep(i, M){
    if(tetrahedralNums[i] % 2 == 0) continue;
    int m = tetrahedralNums[i];
    for(int j = m; j <= 1e6; j++)
      if(dp2[j] > dp2[j - m] + 1)
          dp2[j] = dp2[j - m] + 1;
  }

  while(cin >> N && N){
    cout << dp1[N] << ' ' << dp2[N] << endl;
  }
}

signed main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(9);

  solve();

  return 0;
}