#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int>a(n),vec(n);
  rep(i,n-1){
    cin>>a[i];
    a[i]--;
    vec[a[i]]++;
  }
  rep(i,n)cout<<vec[i]<<endl;
}