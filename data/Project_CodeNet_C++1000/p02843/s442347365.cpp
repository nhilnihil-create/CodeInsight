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
  int X;
  cin>>X;
  int a=X/100, b=X%100;
  if(b%5==0) {
    if(b/5<=a) cout<<1<<endl;
    else cout<<0<<endl;
  }
  else {
    if(b/5+1<=a) cout<<1<<endl;
    else cout<<0<<endl;
  }
}
