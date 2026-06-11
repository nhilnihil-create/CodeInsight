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

ll DP[2][100005];

int main() {
  string L;
  cin>>L;
  DP[0][0] = 1;
  DP[1][0] = 2;
  for(int i=1;i<L.size();++i) {
    if(L[i]=='1') {
      DP[0][i] = (DP[0][i-1]*3%mod+DP[1][i-1])%mod;
      DP[1][i] = DP[1][i-1]*2%mod;
    }
    else {
      DP[0][i] = DP[0][i-1]*3%mod;
      DP[1][i] = DP[1][i-1];
    }
  }
  cout<<(DP[0][L.size()-1]+DP[1][L.size()-1])%mod<<endl;
}

