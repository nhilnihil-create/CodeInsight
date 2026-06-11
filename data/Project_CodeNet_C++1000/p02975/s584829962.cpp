#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main(){
  int n; cin >>n;
  vector<ll> a(n);
  rep(i,n) cin >>a[i];
  sort(a.begin(), a.end());
  if(n%3!=0) {
    if(a[n-1]==0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
  }
  int m=n/3;
  if(a[0]==a[m-1]&&a[m]==a[2*m-1]&&a[2*m]==a[n-1]){
    int x=a[0], y=a[m], z=a[2*m];
    int xy=x^y;
    if(xy==z) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  else cout << "No" << endl;
  return 0;
}