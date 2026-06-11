#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,ans=0;
  cin >>n;
  vector<int> a(n);
  rep(i,n){
    cin>> a[i];
  }
  sort(a.begin(),a.end());
  rep(i,n){
    for(int j=i+1;j<n;j++){
        int lb = lower_bound(a.begin(),a.end(),a[i]+a[j])-a.begin();
        ans += max(lb-(j+1),0);
    }
  }
  cout << ans << endl;
}