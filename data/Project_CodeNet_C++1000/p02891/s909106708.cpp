#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  string t;
  ll k;
  cin >> t >> k;
  if(t.size() == 1){
    cout << k/2 << "\n";
    return 0;
  }
  else if(t.size() == 2){
    if(t[0] == t[1]){
      cout << k << "\n";
      return 0;
    }
    else{
      cout << 0 << "\n";
      return 0;
    }
  }
  ll a = 1, b = 1;
  for(int i = 1 ; i < t.size() ; i ++ ){
    if(t[i] == t[i - 1]) a ++ ;
    else break;
  }
  ll n = t.size();
  for(int i = n - 2; i >= 0 ; i -- ){
    if(t[i] == t[i + 1]) b ++ ;
    else break;
  }
  if(a == n){
    cout << (n*k)/2ll;
    return 0;
  }
  ll res = 0;
  int tot = 1;
  for(int i = 1; i < n; i ++ ){
    if(t[i] == t[i - 1]){
      tot ++ ;
    }
    else{
      res += tot/2;
      tot = 1;
    }
  }
  res += tot/2;
  if(t[0] != t[n-1]){
    res *= k;
    cout << res;
    return 0;
  }
  res -= a/2;
  res -= b/2;
  cout << res * 1ll * k + (a/2) + (b/2) + ((a+b)/2) * 1ll * (k-1);
  return 0;
}