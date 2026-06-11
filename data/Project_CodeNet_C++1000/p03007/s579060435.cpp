#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
ll mod=1e9+7;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
  }
  sort(a.begin(),a.end());
  ll m=a[0];
  ll nn=0;
  for(ll i=0;i<n;i++) {
    if(a[i]<0) nn++;
  }
  if(nn==0) nn++;
  else if(nn==n) nn--;
  for(ll i=nn;i<n-1;i++) {
    m-=a[i];
  }
  for(ll i=0;i<nn;i++) {
    if(i==0) {
      m=a[n-1]-m;
    }
    else {
      m-=a[i];
    }
  }
  cout << m << endl;
  m=a[0];
  for(ll i=nn;i<n-1;i++) {
    cout << m << " " << a[i] << endl;
    m-=a[i];
  }
  for(ll i=0;i<nn;i++) {
    if(i==0) {
      cout << a[n-1] << " " << m << endl;
      m=a[n-1]-m;
    }
    else {
      cout << m << " " << a[i] << endl;
      m-=a[i];
    }
  }
  cout << endl;
}