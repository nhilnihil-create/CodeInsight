#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  ll n;
  cin>>n;
  vector<ll> a(n,0);
  for(int i=0; i<n; i++){
    cin >> a[i];
    a[i] *= 2LL;
    if(i)a[i] += a[i-1];
  }
  ll half = a[n-1]/2LL;
  ll dist = a[n-1];
  for(int i=0; i<n; i++){
    dist = min(dist, abs( half - a[i] ) );
  }
  cout << dist << endl;
}