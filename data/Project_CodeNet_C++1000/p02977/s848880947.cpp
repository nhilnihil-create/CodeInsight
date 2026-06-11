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

bool isbits1(int bits){
  int num = 0;
  int mask = 1;
  while(mask!=0){
    if(bits&mask)++num;
    mask<<=1;
  }
  return num==1;
}

const int N_MAX = 1e5+10;
int n_2[N_MAX];
void init(){
  int n = 1;
  rep(i,N_MAX){
    n_2[i] = n;
    if(2*n==i)n<<=1;
  }
}

int main(void){
  SPEEDUP
  init();
  cout << setprecision(15);
  int N;cin >> N;
  if(isbits1(N)){
    cout << "No" << endl;
    return 0;
  }
  bool check = false;
  if((N&1) == 0) check = true;
  cout << "Yes" << endl;
  cout << N+1 SP N+2 << endl;
  repp(i,1,(N-1)/2+1){
    cout << 2*i+N SP 2*i+1 << endl;
    cout << 2*i+1 SP 1 << endl;
    cout << 1 SP 2*i << endl;
    cout << 2*i SP 2*i+N+1 << endl;
  }
  if(check){
    cout << N SP n_2[N]  << endl;
    int n = N - n_2[N] + 1;
    cout << n SP 2*N << endl;
  }
  return 0;
}
