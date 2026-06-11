#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

ll n;

ll f(ll k){
  ll tmp = n;
  while(n % k == 0){
    n /= k;
  }
  if(n % k == 1){
    n = tmp;
    return 1;
  }
  n = tmp;
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  cin >> n;
  ll t = n - 1;
  ll cnt = 0, ans = 0;
  for(int i = 2; (ll)i * i <= t; i++){
    if(t % i == 0){
      ans++;
      if(t / i != i) ans++;
    }
  }
  if(t > 1) ans++;

  vector < ll > v;
  for(int i = 2; (ll)i * i <= n; i++){
    if(n % i == 0){
      v.push_back(i);
      if(n / i != i) v.push_back(n / i);
    }
  }
  if(n > 1) v.push_back(n);

  for(auto i : v){
    ans += f(i);
  }

  cout << ans << endl;
}
