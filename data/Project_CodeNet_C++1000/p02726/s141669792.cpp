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
  int N, X, Y;
  cin>>N>>X>>Y;
  X--;
  Y--;
  map<int, int> amap;
  int ans;
  for(int i=0;i<N;++i) {
    for(int j=i+1;j<N;++j) {
      ans = j-i;
      ans = min(ans, abs(i-X)+1+abs(Y-j));
      ans = min(ans, abs(i-Y)+1+abs(X-j));
      amap[ans]++;
    }
  }
  for(int i=1;i<N;++i) cout<<amap[i]<<endl;
}

