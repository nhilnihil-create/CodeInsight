#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  ll ans = 0;
  map<int,int> mp;
  rep(i,n){
    ans += mp[i-a[i]];
    mp[i+a[i]]++;
  }

  cout << ans << endl;
  
}
