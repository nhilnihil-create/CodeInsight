#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll count_divs(ll n){
  ll res = 1;
  for(ll i = 2;i * i <= n;i++){
    ll cnt = 0;
    if(n % i == 0){
      while(n % i == 0){
        n /= i;
        cnt++;
      }
      res *= (cnt + 1);
    }
  }
  if(n != 1)
    res *= 2;
  return res;
}

vector<ll> get_divs(ll n){
  vector<ll> res;
  for(ll i = 1;i * i <= n;i++){
    if(n % i == 0){
      res.push_back(i);
      if(i != n / i)
        res.push_back(n / i);
    }
  }
  return res;
}
bool check(ll n, ll k){
  ll r = n % k;
  if(r == 1)
    return true;
  else if(r == 0)
    return check(n / k, k);
  else
    return false;
}
int main()
{
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  ll n;
  cin >> n;
//  ll brute = 0;
//  for(int i = 2;i <= n;i++){
//    if(check(n, i)){
//      cout << i << ' ' << ((n + 1) % i == 0) << endl;
//      brute++;
//    }
//  }
//  cout << brute << endl;
  ll res = count_divs(n - 1) - 1;
  vector<ll> divs = get_divs(n);
//  cout << res << endl;
  for(auto el : divs){
    if(el != 1 && check(n, el))
      res++;
  }
  cout << res;
  return 0;
}
