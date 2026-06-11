#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n,k,q;cin>>n>>k>>q;
  vector<int> a(q),ans(n,k-q);
  rep(i,q){
    cin>>a[i];
    a[i]--;
    ans[a[i]]++;
  }
  rep(i,n){
    if(ans[i]>0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}