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

ll DP[13][100005];

int main() {
  string S;
  cin>>S;
  if(S[0]=='?') {
    for(int i=0;i<10;++i) DP[i][0] = 1;
  }
  else {
    DP[S[0]-'0'][0] = 1;
  }
  for(int i=1;i<S.size();++i) {
    if(S[i]=='?') {
      for(int j=0;j<13;++j) {
        for(int k=0;k<10;++k) {
          DP[(10*j+k)%13][i] += DP[j][i-1];
          DP[(10*j+k)%13][i] %= mod;
        }
      }
    }
    else {
      for(int j=0;j<13;++j) {
        DP[(10*j+(S[i]-'0'))%13][i] += DP[j][i-1];
        DP[(10*j+(S[i]-'0'))%13][i] %= mod;
      }
    }
  }
  cout<<DP[5][S.size()-1]<<endl;
}

