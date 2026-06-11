#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<n;i++)

int main() {
 ll n ;cin >> n;
 vector<ll> h(n);
 rep(i,n)cin >> h[i];
  ll  maxh=h[0]; bool flag=1;
  rep1(i,n){
    if(h[i]<maxh-1)flag=0;
    else if(h[i]>=maxh) maxh=h[i];
  }

  if(flag)cout << "Yes" << endl;
  else cout << "No" << endl;

}
