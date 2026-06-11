#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>data(1e6+1);
  ll ans = 1,mod = 1e9+7;
  rep(i,0,n){
    int a;
    cin >> a;
    if(a == 0) ans *= 3-data[a];
    else ans *= data[a-1]-data[a];
    data[a]++;
    ans %= mod;
  }
  cout << ans << endl;
}