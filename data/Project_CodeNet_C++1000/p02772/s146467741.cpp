#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  ll n;
  cin >> n;
  vector<ll>a(n);
  for(ll i=0;i<n;i++){
    cin >> a[i];
  }
  bool judge=true;
  for(ll i=0;i<n;i++){
    if(a[i]%2==0){
      if(a[i]%3!=0&&a[i]%5!=0){
        judge=false;
      }
    }
  }
  if(judge) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}