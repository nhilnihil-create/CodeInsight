#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
  int N, K;
  cin>>N>>K;
  string S;
  cin>>S;
  bool l;
  if(S[0]=='L') l = true;
  else l = false;
  int ans = 0;
  for(int i=1;i<S.size();++i){
    if(l){
      if(S[i]=='R'){
        ans++;
        l = false;
      }
    }
    else{
      if(S[i]=='L'){
        ans++;
        l = true;
      }
    }
  }
  ans++;
  int ans1 = 0;
  for(int i=0;i<S.size()-1;++i){
    if(S[i]==S[i+1]) ans1++;
  }
  int ans2 = ans1 + 2*min(K, max(0, (ans-2)/2));
  int tmpK = K;
  K -= min(tmpK, max(0, (ans-2)/2));
  ans -= 2*min(tmpK, max(0, (ans-2)/2));
  if(K==0) cout<<ans2<<endl;
  else if(ans>2) cout<<ans2+2<<endl;
  else if(ans==2) cout<<ans2+1<<endl;
  else cout<<ans2<<endl;
}

