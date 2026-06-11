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
  ll T1, T2, A1, A2, B1, B2;
  cin>>T1>>T2>>A1>>A2>>B1>>B2;
  if(A1-B1<0) {
    swap(A1, B1);
    swap(A2, B2);
  }
  A1 = A1 - B1;
  A2 = A2 - B2;
  if(A1*T1+A2*T2>0) {
    cout<<0<<endl;
    return 0;
  }
  else if(A1*T1+A2*T2==0) {
    cout<<"infinity"<<endl;
    return 0;
  }
  ll x = abs(A1*T1+A2*T2);
  ll ans = 1;
  if(A1*T1%x==0) {
    ans += 2*(A1*T1/x) - 1;
  }
  else {
    ans += 2*(A1*T1/x);
  }
  cout<<ans<<endl;
}

