#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

vec ans;
void dfs(ll id,ll sum) {
  if(sum==0) {
    for(ll i=1;i<10;i++) {
      ll tsum=sum+i;
      ans.push_back(tsum);
      dfs(id-1,tsum);
    }
  }
  else {
    for(ll i=-1;i<2;i++) {
      ll tmp=i+sum%10;
      if(tmp<0||tmp>=10) continue;
      ll tsum=sum*10+tmp;
      ans.push_back(tsum);
      if(id) {
        dfs(id-1,tsum);
      }
    }
  }
}

int main() {
  ll k;
  cin >> k;
  dfs(10,0);
  sort(ans.begin(),ans.end());
  cout << ans[k-1] << endl;
}