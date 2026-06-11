#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
const ll big=1e18;
const double PI=2*asin(1);

ll min(ll a, ll b) {
  if(a>b) return b;
  else return a;
}

int main() {
  ll S;
  cin>>S;
  ll x1=1e9, x2, y1, y2;
  y2 = min(1e9, S/x1 + 1);
  x2 = x1*y2 - S;
  y1 = 1;
  cout<<0<<" "<<0<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
}
