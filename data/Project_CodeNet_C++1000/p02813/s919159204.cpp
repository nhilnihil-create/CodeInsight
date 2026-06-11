#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> vec(n),p(n),q(n);
  rep(i,n)vec[i]=i+1;
  map<vector<int>,int> mp;
  rep(i,n)cin>>p[i];
  rep(i,n)cin>>q[i];
  do{
    mp[vec]=mp.size();
  }while(next_permutation(all(vec)));
  int ans=abs(mp[p]-mp[q]);
  cout<<ans<<endl;
}