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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll X;
  cin>>X;
  ll ans1, ans2;
  for(ll A=-3000;A<=3000;++A) {
    for(ll B=-3000;B<=3000;++B) {
      if(A*A*A*A*A-B*B*B*B*B==X) {
        ans1 = A;
        ans2 = B;
      }
    }
  }
  cout<<ans1<<" "<<ans2<<endl;
}

