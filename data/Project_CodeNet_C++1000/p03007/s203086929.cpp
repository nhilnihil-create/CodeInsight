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
  ll A[N];
  vector<int> plus, minus;
  int mini = inf, maxi = -inf;
  int miniind = -1, maxiind = -1;
  for(int i=0;i<N;++i) {
    cin>>A[i];
    if(A[i]<0) minus.push_back(i);
    else plus.push_back(i);
    if(mini>A[i]) {
      mini = A[i];
      miniind = i;
    }
    if(maxi<=A[i]) {
      maxi = A[i];
      maxiind = i;
    }
  }
  vector<pair<int, int> > ans;
  for(int i=0;i<minus.size();++i) {
    if(maxiind==minus[i] || miniind==minus[i]) continue;
    ans.push_back(mp(maxi, A[minus[i]]));
    maxi = maxi-A[minus[i]];
  }
  for(int i=0;i<plus.size();++i) {
    if(maxiind==plus[i] || miniind==plus[i]) continue;
    ans.push_back(mp(mini, A[plus[i]]));
    mini = mini - A[plus[i]];
  }
  if(plus.size()>0 && minus.size()>0) {
    cout<<maxi-mini<<endl;
    for(int i=0;i<ans.size();++i) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    cout<<maxi<<" "<<mini<<endl;
  }
  else if(plus.size()==0) {
    cout<<maxi-mini<<endl;
    for(int i=0;i<ans.size();++i) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    cout<<maxi<<" "<<mini<<endl;
  }
  else {
    cout<<maxi-mini<<endl;
    for(int i=0;i<ans.size();++i) cout<<ans[i].fi<<" "<<ans[i].se<<endl;
    cout<<maxi<<" "<<mini<<endl;
  }
}

