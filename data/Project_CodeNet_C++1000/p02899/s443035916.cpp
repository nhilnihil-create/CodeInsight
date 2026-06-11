#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int>a(n+1);
  vector<pair<int,int>> pr(n+1);
  for(int i=1;i<=n;i++){
    cin>>a[i];
    pr[i]=make_pair(a[i],i);
  }
  sort(all(pr));
  for(int i=1;i<=n;i++){
    cout<<pr[i].second<<" ";
  }
  cout<<endl;
}