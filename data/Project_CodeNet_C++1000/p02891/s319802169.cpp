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
  ll K;
  cin>>K;
  if(S[0]!=S[S.size()-1]) {
    ll ans = 0;
    for(int i=0;i<S.size()-1;++i) {
      if(S[i]==S[i+1]) {
        ans++;
        i++;
      }
    }
    cout<<ans*K<<endl;
    return 0;
  }
  int index1=0, index2=0;
  bool ok = false;
  for(int i=0;i<S.size();++i) {
    index1 = i;
    if(S[i]!=S[0]) {
      ok = true;
      break;
    }
  }
  for(int i=S.size()-1;i>=0;--i) {
    index2 = i+1;
    if(S[i]!=S[S.size()-1]) {
      ok = true;
      break;
    }
  }
  if(!ok) {
    cout<<S.size()*K/2<<endl;
    return 0;
  }
  ll ans = 0;
  for(int i=index1;i<index2;++i) {
    if(S[i]==S[i+1]) {
      ans++;
      i++;
    }
  }
  ll zero = 0;
  ans *= max(zero, (K-2));
  ans += (index1+(S.size()-index2))/2*(K-1);
  for(int i=0;i<index2;++i) {
    if(S[i]==S[i+1]) {
      ans++;
      i++;
    }
  }
  for(int i=S.size()-1;i>=index1;--i) {
    if(S[i]==S[i-1]) {
      ans++;
      i--;
    }
  }
  cout<<ans<<endl;
}

