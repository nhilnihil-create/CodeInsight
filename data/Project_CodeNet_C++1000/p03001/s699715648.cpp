#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll W, H, x, y;
  cin>>W>>H>>x>>y;
  bool can = false;
  if(x*2==W && y*2==H) can = true;
  double ww=W, hh=H;
  if(can) cout<<setprecision(20)<<ww*hh/2<<" "<<1<<endl;
  else cout<<setprecision(20)<<ww*hh/2<<" "<<0<<endl;
}

