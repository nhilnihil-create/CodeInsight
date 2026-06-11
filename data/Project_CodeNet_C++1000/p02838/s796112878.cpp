#include <bits/stdc++.h>

using namespace std;
const long long MOD=1e9+7;

int main(){
  long long n, a[300009], cnt[62];
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  for(int i=0;i<n;i++){
    for(int j=0;j<60;j++){
      if((a[i]>>j)&1)cnt[j]++;
    }
  }
  long long base=1;
  long long ans = 0;
  for(int i=0;i<60;i++){
    long long value=0;
    value+=base*cnt[i];
    value%=MOD;
    value *= n-cnt[i];
    value%=MOD;
    ans += value;
    ans %= MOD;
    base = (base * 2) % MOD;
  }
  cout << ans << endl;
}

