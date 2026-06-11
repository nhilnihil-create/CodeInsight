#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,k,q;cin>>n>>k>>q;
  vector<int> a(q),ans(n);
  rep(i,q){
    cin>>a[i];
    ans[a[i]-1]++;
  }
  rep(i,n){
    if(q-ans[i]<k)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}