#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;

int main(){
  int n; cin >> n;
  vector<ll> ball(200005);
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
    ball[a[i]] ++;
  }
  
  ll sum = 0;
  rep(i, 200005){
    sum += ball[i]*(ball[i]-1)/2;
  }
  
  rep(i, n){
    ll ans = sum - ball[a[i]] + 1;
    cout << ans << endl;
  }

  return 0;
}
