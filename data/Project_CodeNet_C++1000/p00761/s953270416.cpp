#include<bits/stdc++.h>
#include<sstream>
using namespace std;

typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
#define rrep(i, m, n) for(int (i)=(m); (i)<(n);  (i)++)
#define erep(i, m, n) for(int (i)=(m); (i)<=(n); (i)++)
#define  rep(i, n)    for(int (i)=0; (i)<(n);  (i)++)
#define rrev(i, m, n) for(int (i)=(n)-1; (i)>=(m); (i)--)
#define erev(i, m, n) for(int (i)=(n); (i)>=(m); (i)--)
#define  rev(i, n)    for(int (i)=(n)-1; (i)>=0; (i)--)
#define vrep(i, c)    for(__typeof((c).begin())i=(c).begin(); i!=(c).end(); i++)
#define  ALL(v)       (v).begin(), (v).end()
#define pb            push_back
template<class T, class S> inline pair<T, S> mp(T x, S y){ return make_pair(x, y); }
template<class T, class S> inline bool minup(T& m, S x){ return m>(T)x ? (m=(T)x, true) : false; }
template<class T, class S> inline bool maxup(T& m, S x){ return m<(T)x ? (m=(T)x, true) : false; }

static const int    INF = 1000000000;
static const ll     MOD = 1000000007LL;
static const double EPS = 1E-12;

template<typename T> inline void _tostr(const T t, string& s){ostringstream o;o<<t;s=o.str();}
template<typename T> inline void _toint(const string s, T& n){istringstream i(s);n;i>>n;}

int a, L;
//char to[10];
string to;
int m, M;

int main()
{
  while(cin >> to >> L, L){
    map<string, int> hm;
    int cnt = 1;
    while(hm[to] < 1){
      hm[to] = cnt++;
      rep(i, to.size()-L) to += '0';
      sort(ALL(to));
      _toint(to, m);
      reverse(ALL(to));
      _toint(to, M);
      a = M - m;
      _tostr(a, to);
    }
    cout << hm[to] - 1 << ' ' << to << ' ' << cnt - hm[to] << endl;
  }

  return 0;
}