#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
  
int main() {
  ll t1,t2,a1,a2,b1,b2;
  cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
  ll v1 = a1-b1;
  ll v2 = a2-b2;
  if(t1*v1+t2*v2 == 0) {
    cout << "infinity" << endl;
    return 0;
  }
  if(v1 < 0) {
    v1 *= -1;
    v2 *= -1;
  }
  if(t1*v1+t2*v2>0) {
    cout << 0 << endl;
    return 0;
  }
  ll h = v1*t1;
  ll d = -1 * (t1*v1+t2*v2);
  if(h%d != 0) {
    cout << 2*(h/d)+1 << endl;
  } else {
    cout << 2*(h/d) << endl;
  }
  return 0;
}