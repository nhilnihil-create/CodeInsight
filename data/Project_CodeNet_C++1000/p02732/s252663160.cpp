#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  vector<ll> b(n+2,0);
  for(int i = 0; i < n; i++) b[a[i]]++;
  ll ans = 0;
  for(int i = 0; i < n+1; i++) ans += b[i]*(b[i]-1)/2;
  
  for(int k = 0; k < n; k++){
    cout << ans - b[a[k]]*(b[a[k]]-1)/2 + (b[a[k]]-1)*(b[a[k]]-2)/2 << endl;
  }
  return 0;
}