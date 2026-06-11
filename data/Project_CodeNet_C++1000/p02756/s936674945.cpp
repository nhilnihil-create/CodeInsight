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
  string S;
  cin>>S;
  string ans1, ans2;
  bool gyaku = false;
  int Q;
  cin>>Q;
  int query, x;
  char c;
  for(int i=0;i<Q;++i) {
    cin>>query;
    if(query==1) gyaku ^= 1;
    else {
      cin>>x>>c;
      if(gyaku) {
        if(x==1) ans2.push_back(c);
        else ans1.push_back(c);
      }
      else {
        if(x==1) ans1.push_back(c);
        else ans2.push_back(c);
      }
    }
  }
  string ans;
  if(gyaku) {
    reverse(S.begin(), S.end());
    reverse(ans2.begin(), ans2.end());
    ans = ans2+S+ans1;
  }
  else {
    reverse(ans1.begin(), ans1.end());
    ans = ans1+S+ans2;
  }
  cout<<ans<<endl;
}

