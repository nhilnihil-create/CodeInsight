#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

long long dat[500200], dat2[500200];
int n = 1;
int p[100005];
ll LL[100005], LR[100005], RL[100005], RR[100005];

void init(int _n){
  while (n<_n) n*= 2;
  for (int i=0; i<2*n - 1; i++) dat[i] = LINF;
  for (int i=0; i<2*n - 1; i++) dat2[i] = -LINF;
  return;
}

void built() {
  for (int i=n-2; i>=0; i--) {
    dat[i] = min(dat[2*i+1], dat[2*i+2]);
    dat2[i] = max(dat2[2*i+1], dat2[2*i+2]);
  }
  return;
}

void update(int k, long long a) {
  k += n - 1;
  dat[k] = a;
  while (k > 0) {
    k = (k-1)/2;
    dat[k] = min(dat[2*k+1], dat[2*k+2]);
  }
  return;
}

long long query(int a, int b, int l, int r, int k) {
  if (b <= l || a >= r) return LINF;
  if (a <= l && b >= r) return dat[k];
  
  long long vl = query(a, b, l, (r+l)/2, 2*k+1);
  long long vr = query(a, b, (r+l)/2, r, 2*k+2);
  return min(vl, vr);
}

void update2(int k, long long a) {
  k += n - 1;
  dat2[k] = a;
  while (k > 0) {
    k = (k-1)/2;
    dat2[k] = max(dat2[2*k+1], dat2[2*k+2]);
  }
  return;
}

long long query2(int a, int b, int l, int r, int k) {
  if (b <= l || a >= r) return -LINF;
  if (a <= l && b >= r) return dat2[k];
  
  long long vl = query2(a, b, l, (r+l)/2, 2*k+1);
  long long vr = query2(a, b, (r+l)/2, r, 2*k+2);
  return max(vl, vr);
}

int main(void) {
  int N;
  cin >> N;

  rep(i, 0, N) cin >> p[i];
  init(N+5);
  
  rep(i, 0, N) {
      dat[p[i]+n-1] = (ll)i;
      dat2[p[i]+n-1] = (ll)i;
    }
  
  built();
  
  rep (i, 0, N) {
      ll l = LINF, r = LINF;
      l = query(p[i]+1, N+1, 0, n, 0);
      if (l!=LINF) {
          update(p[l], LINF);
          r = query(p[i]+1, N+1, 0, n, 0);
          update(p[l], l);   
      }
      update(p[i], LINF);
      if(l==LINF) l=N;
      if(r==LINF) r=N;

      RL[p[i]] = l;
      RR[p[i]] = r;
  }

  for (int i=N-1; i>=0; i--) {
      ll l = -LINF, r = -LINF;
      r = query2(p[i]+1, N+1, 0, n, 0);
      if (r!=-LINF) {
          update2(p[r], -LINF);
          l = query2(p[i]+1, N+1, 0, n, 0);
          update2(p[r], r);   
      }
      update2(p[i], -LINF);
      
      if(l==-LINF) l=-1;
      if(r==-LINF) r=-1;
      
      LL[p[i]] = l;
      LR[p[i]] = r;
  }

  ll ans = 0;
  rep(i, 0, N) {
      int x = p[i];
      //printf("x:%d, LL[x]:%lld, LR[x]:%lld, RL[x]:%lld, RR[x]:%lld\n", x, LL[x], LR[x], RL[x], RR[x]);
      ans += (RR[x]-RL[x])*(i-LR[x])*x;
      ans += (LR[x]-LL[x])*(RL[x]-i)*x;
      //printf("%lld\n", ans);
  }
  
  
  
  cout << ans << endl;
    return 0;
}



