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

struct Coo{
  double x,y,deg;
};

bool comp(const Coo& l, const Coo& r){
  return l.deg < r.deg;
}

int dec(int i,int N){
  return (i+N-1)%N;
}

int inc(int i,int N){
  return (i+1)%N;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int N;cin >> N;
  vector<Coo> v(N);
  rep(i,N){
    cin >> v[i].x >> v[i].y;
    v[i].deg = 180.0/M_PI*atan2(v[i].x,v[i].y);
    if(v[i].deg < 0) v[i].deg+=360.0;
  }
  sort(all(v),comp);

  double ans = 0.0;
  double x_ = 0, y_ = 0;
  rep(i,N){
    x_ += v[i].x;
    y_ += v[i].y;
  }
  rep(i,N) repp(j,i+1,N+1){
    double x = 0, y = 0;
    repp(k,i,j){
      x += v[k].x;
      y += v[k].y;
    }
    ans = max(ans,sqrt(x*x+y*y));
    ans = max(ans,sqrt((x-x_)*(x-x_)+(y-y_)*(y-y_)));
  }
  cout << ans << endl;
  return 0;
}
