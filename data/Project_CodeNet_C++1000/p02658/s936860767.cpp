#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
using pii = pair<int,int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back

const ll MAX=1e18;

int main() {
  int n; cin>>n;
  vll a(100010);
  ll ans=1;
  rep(i,n) {
    cin>>a[i];
    if(a[i]==0) {
      cout<<0<<endl;
      return 0;
    }
  }
  rep(i,n) {
    if(ans<=MAX/a[i]) {
      ans*=a[i];
    } else {
      ans=-1;
      break;
    }
  }
  cout<<ans<<endl;
}
