#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define ALL(x) x.begin(),x.end()
#define EPS (1e-8)
#define equals(a,b) (fabs((a)-(b))<EPS)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

inline bool LT(double a,double b) { return !equals(a,b) && a < b; }
inline bool LTE(double a,double b) { return equals(a,b) || a < b; }

#define MAX (1<<19)
int BIT[MAX+1];

int sum(int k) {
  int ret = 0;
  for(++k; k > 0; k -= k & -k) ret += BIT[k];
  return ret;
}

void add(int k, int x) {
  for(++k; k < MAX; k += k & -k) BIT[k] += x;
}

bool debug = 0;
int mm;
  
bool check(int sp, int x) {
  //cout << "??? sp = " << sp << ", x = " << x << " " << sum(sp+x) << " - " << ((sp-1)>=0?sum(sp-1):0) << endl;
  x += sp;
  if( x >= mm ) return false;
  return sum(x) - ((sp-1)>=0?sum(sp-1):0) == ( x - sp + 1 );
}

void solve(int n,vector<int> &vec) {
  mm = vec.size();
  vector<int> mvec = vec;
  rep(i,(int)mvec.size()) mvec[i] = mvec[i] * -1;

  if( debug ) {
    cout << "[vec]---" << endl;
    rep(i,(int)vec.size()) {
      cout << "* " << i << "-th: " << vec[i] << endl;
    }
  }
  
  vector<int> cur;
  cur.pb(0);
  add(0,1);
  rep(_,n) {
    if( debug ) {
      cout << "* Phase " << _ << ": "<< endl;
    }
    vector<int> nex = cur;
    rep(i,(int)cur.size()) {
      int v = mvec[cur[i]];
      int sp = upper_bound(ALL(mvec),v) - mvec.begin();
      if( debug ) {
	cout << "  v  = " << v << endl;
	cout << "  sp = " << sp << " ( " << ((sp<(int)vec.size())?vec[sp]:-123) << " )" << endl;
      }
      if( sp >= (int)mvec.size() ) { puts("No"); return; }

      ll L = 0, R = (int)mvec.size();
      while( R - L ) {
	ll M = ( L + R ) / 2LL;
	if( check(sp, M) ) L = M + 1;
	else               R = M;
	//cout << M << ": [" << L << "," << R << "]" << endl;
      }
      int x = L;
      x += sp;
      if( debug ) {
	cout << "  x  = " << x << " ( " << ((x<(int)vec.size())?vec[x]:-123) << " )" << endl;
      }
      if( x >= (int)vec.size() ) { puts("No"); return; }
      add(x,1);
      nex.pb(x);
    }
    cur = nex;
  }
  puts("Yes");
}

int main() {
  int n;
  cin >> n;
  vector<int> vec(1<<n);
  rep(i,(1<<n)) cin >> vec[i];
  sort(ALL(vec),greater<int>());
  solve(n,vec);
  return 0;
}
