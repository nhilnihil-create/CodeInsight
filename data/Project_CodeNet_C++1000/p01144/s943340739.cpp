#include<bits/stdc++.h>
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

int n, m;
int d, p;

int main()
{
  while(cin >> n >> m, n){
    priority_queue<pii> que;
    rep(i, n){
      cin >> d >> p;
      que.push(mp(p, d));
    }

    while(m > 0 && !que.empty()){
      p = que.top().first;
      d = que.top().second;
      if(d <= m){
        m -= d;
        que.pop();
      }
      else{
        que.pop();
        que.push(mp(p, d - m));
        m = 0;
     }
    }

    int res = 0;
    while(!que.empty()){
      res += que.top().first * que.top().second;
      que.pop();
    }

    cout << res << endl;
  }

  return 0;
}