#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0,i##_max=(N);i<i##_max;++i)
#define repp(i,l,r) for(int i=(l),i##_max=(r);i<i##_max;++i)
#define per(i,N) for(int i=(N)-1;i>=0;--i)
#define perr(i,l,r) for(int i=r-1,i##_min(l);i>=i##_min;--i)
#define all(arr) (arr).begin(), (arr).end()
#define SP << " " <<
#define SPF << " "
#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false);
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
  typedef long long ll;
  typedef pair<int,int> PII;
  typedef pair<char,char> PCC;
  typedef pair<ll,ll> PLL;
  typedef pair<char,int> PCI;
  typedef pair<int,char> PIC;
  typedef pair<ll,int> PLI;
  typedef pair<int,ll> PIL; 
  typedef pair<ll,char> PLC; 
  typedef pair<char,ll> PCL; 

inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}
inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}
inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}

template<typename T>
struct BIT{
  int n;
  vector<T> d;
  BIT(int n=0):n(n),d(n+1){}

  T sum(int k){
    T ret = 0;
    for(++k;k>0;k-=k&-k) ret += d[k];
    return ret;
  }

  void add(int k, T x=1){
    for(++k; k<=n; k+= k&-k) d[k] += x;
  }
};

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int N;cin >> N;
  vector<int> v(N+1,0);
  vector<int> w(N+1,0);
  rep(i,N){
    int x;cin >> x; --x;
    ++v[x];
  }
  rep(i,N) ++w[v[i]];
  rep(i,N+1) v[i] = w[i];
  rep(i,N) v[i+1] += v[i];
  rep(i,N+1) w[i] *= i;
  rep(i,N) w[i+1] += w[i];
  vector<int> h(N+1);
  h[0] = MAX_I;
  repp(X,1,N+1) h[X] = (w[X] + X*(v[N] - v[X]))/X;
  int id = N;
  repp(k,1,N+1){
    while(k>h[id])id--;
    cout << id << endl;
  }
  return 0;
}
