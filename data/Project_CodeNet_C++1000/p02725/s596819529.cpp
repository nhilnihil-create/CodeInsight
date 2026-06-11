#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
  int k,n,mini=0; cin>>k>>n;
  vector<int> a(n),b(n-1);
  rep(i,n) cin>>a[i];
  for(int i=0;i<n-1;i++){
    mini=max(mini,a[i+1]-a[i]);
  }
  mini=max(mini,a[0]+k-a[n-1]);
  cout<<k-mini;
}