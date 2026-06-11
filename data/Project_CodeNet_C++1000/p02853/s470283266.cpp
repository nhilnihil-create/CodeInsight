#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(n) n.begin(),n.end()

int money(int n){
  if(n==1) return 300000;
  if(n==2) return 200000;
  if(n==3) return 100000;
  return 0;
}

int main() {
  int x,y;
  cin >> x >> y;
  if(x==1 && y==1) cout << 1000000 << endl;
  else cout << money(x) + money(y) << endl;
  return 0;
}
