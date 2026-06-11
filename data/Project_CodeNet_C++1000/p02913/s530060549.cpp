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
  int N;
  cin>>N;
  string S;
  cin>>S;
  int ans = 0;
  int tmp;
  for(int l=0;l<S.size();++l) {
    tmp = 0;
    for(int i=0;i+l<S.size();++i) {
      if(S[i]==S[i+l]) tmp++;
      else {
        ans = max(ans, min(l, tmp));
        tmp = 0;
      }
    }
    ans = max(ans, min(l, tmp));
  }
  cout<<ans<<endl;
}

