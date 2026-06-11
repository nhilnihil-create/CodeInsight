#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  sort(a.begin(),a.end());
  int mi=a[0], ma=a[n-1];
  vector<int> plus,minus;
  rep(i,n){
    if(i==0||i==n-1) continue;
    if(a[i]>0) plus.push_back(a[i]);
    else minus.push_back(a[i]);
  }
  vector<P> ans;
  int m=mi;
  for(auto x : plus){
    ans.push_back(make_pair(m,x));
    m=m-x;
  }
  ans.push_back(make_pair(ma,m));
  m=ma-m;
  for(auto x : minus){
    ans.push_back(make_pair(m,x));
    m=m-x;
  }
  cout<<m<<endl;
  for(auto p : ans){
    cout<<p.first<<" "<<p.second<<endl;
  }
}