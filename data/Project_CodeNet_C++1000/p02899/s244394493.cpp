#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<pair<int,int>> pr(n);
  rep(i,n){
    int a;cin>>a;
    pr[i]=make_pair(a,i+1);
  }
  sort(all(pr));
  rep(i,n)cout<<pr[i].second<<" ";
  cout<<endl;
}