#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  rep(i,n) cin >> v[i];
  sort(v.begin(),v.end());
  if(n%3!=0) {
    if(v[n-1]==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }
  int x=n/3;
  if(v[0]==v[x-1]&&v[x]==v[2*x-1]&&v[2*x]==v[n-1]){
    int a=v[0];
    int b=v[x];
    int c=v[2*x];
    int d=a^b;
    if(d==c) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else cout << "No" << endl;
}
