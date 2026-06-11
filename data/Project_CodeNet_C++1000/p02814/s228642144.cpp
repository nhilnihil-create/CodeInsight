#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl;
// *min_element(c + l, c + r) *max_element(c + l, c + r)
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// struct Edge {
//   int to, id;
//   Edge(int to, int id): to(to), id(id) {}
// };

long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

long long LCM(long long a, long long b) {
    return a / GCD(a, b) * b;
}

ll a[100010];


int main() {
  ll n,m;cin>>n>>m;
  rep(i,n) {
    cin>>a[i];
    a[i]/=2;
  }
  ll cnt=0,a_0=a[0];
  while(1) {
    if(a_0%2==0) {
      cnt++;
      a_0/=2;
    }else {
      break;
    }
  }
  rep(i,n){
    if((a[i]%(1<<cnt)!=0) || (a[i]%(1<<(cnt+1))==0)) {
      cout<<0<<endl;
      return 0;
    }
  }
  
  ll lcm=1;
  rep(i,n) {
    lcm = LCM(lcm,a[i]);
  }
  cout<<(m/lcm+1)/2<<endl;
}