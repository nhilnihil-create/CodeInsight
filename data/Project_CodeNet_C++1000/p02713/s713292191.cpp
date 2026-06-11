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

int gcd(int a, int b) {
  int v0=a, v1=b, v2=v0%v1;
  while(v2>0) {
    v0 = v1;
    v1 = v2;
    v2 = v0%v1;
  }
  return v1;
}

int main() {
  int K;
  cin>>K;
  int ans = 0;
  for(int a=1;a<=K;++a) {
    for(int b=1;b<=K;++b) {
      for(int c=1;c<=K;++c) {
        ans += gcd(a, gcd(b, c));
      }
    }
  }
  cout<<ans<<endl;
}

