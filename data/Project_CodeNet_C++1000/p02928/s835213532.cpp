#include <bits/stdc++.h>
using namespace std;

using ll=long long;
const ll MOD=1000000007;

int main() {
  ll n,k;
  cin >> n >> k;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
  }
  ll c=0;
  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      if(a[i]>a[j])
        c++;
    }
  }
  //cout << c << endl;
  ll b=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(a[i]>a[j]){
        b++;
      }
    }
  }
  //cout << b << endl;
  ll ans=0;
  ans +=(c*k)%MOD;
  ans +=(((k*(k-1)/2)%MOD)*b)%MOD;
  cout << ans%MOD << endl;
}