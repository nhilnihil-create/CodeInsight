#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll money = 1000;
  rep(i,n-1){
    ll kabu=0;
    if(a[i] < a[i+1]){
      kabu = money/a[i];
      money %= a[i];
      money += kabu*a[i+1];
    }
  }
  cout << money << endl;
}
