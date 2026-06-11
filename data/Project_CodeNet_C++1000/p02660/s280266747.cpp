#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n;
  cin >> n;
  vector<ll> kosuu(10000,0);
  ll ruton = pow(n, 0.5);
  ll i=2, j=-1;
  int ans = 0;
  while(n!=1){
    if(n%i==0)j++;
    while(n%i==0){
      kosuu[j]++;
      n/=i;
    }
    i++;
    if(i==ruton){
      if(n==1) break;
      else{
        ans++;
        break;
      }
    }
  }

  rep(i,10000){
    int j=1;
    while(kosuu[i]-j >= 0){
      kosuu[i] -= j;
      j++;
      ans++;
    }
  }
  cout << ans << endl;
}
