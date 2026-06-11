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
  int M, D;
  cin>>M>>D;
  int ans = 0;
  for(int i=1;i<=M;++i) {
    for(int j=22;j<=D;++j) {
      if(j%10<2) continue;
      if((j/10)*(j%10)==i) ans++;
    }
  }
  cout<<ans<<endl;
}

