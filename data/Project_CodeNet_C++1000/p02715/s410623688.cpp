#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1000000007;

int Ep(int a, int x){
  if(x == 1) return a;
  int num = Ep(a, x/2);
  if(x%2) return (ll)num *num %MOD *a %MOD;
  else return (ll)num *num %MOD;
}

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> d(k+1);
  for(int i=k; i>0; --i){
    int num = k/i;
    num = Ep(num,n);
    for(int j=i*2; j<=k; j+=i){
      num -= d[j];
      if(num < 0) num += MOD;
    }
    d[i] = num;
  }
  int ans = 0;
  for(int i=1; i<=k; ++i){
    ans += (ll)i * d[i] %MOD;
    ans %= MOD;
  }
  cout << ans << endl;
}