#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){
    cin >> a.at(i);
  }
  ll ans=0;
  rep(i,n){
     ans=ans^a.at(i);
  }
  rep(i,n){
    ll p=ans;
    p=ans^a.at(i);
    cout << p << " ";
  }
}