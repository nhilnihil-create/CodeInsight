#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  map <ll, ll> ma;
  bool flag = true;
  for(int i=0; i<n; i++){
    int a; cin >> a;
    ma[a]++;
    if(ma[a]==2) flag=false;
  }
  
  if(flag) cout << "YES" << endl;
  else cout << "NO" << endl;


  return 0;
}