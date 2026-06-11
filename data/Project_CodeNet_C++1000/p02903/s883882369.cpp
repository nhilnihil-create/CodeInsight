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
  int H, W, A, B;
  cin>>H>>W>>A>>B;
  int ans[H][W];
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      if((i<H-B && j<W-A) || (i>=H-B && j>=W-A)) ans[i][j] = 0;
      else ans[i][j] = 1;
    }
  }
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      cout<<ans[i][j];
    }
    cout<<endl;
  }
}

