#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  
  vector<ll> a(n);
  for(ll i=0; i<n; i++){
    cin>>a[i];
  }
  
  ll result=0;
  ll shinchomax=a[0];
  for(ll i=1; i<n; i++){
    ll diff=shinchomax-a[i];
    if(diff>0) result+=diff;
    else shinchomax=a[i];
  }
  
  cout << result << endl;
}