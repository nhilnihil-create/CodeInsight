#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<pair<string,int>> pr(n);
  int cnt=0;
  rep(i,n){
    string s;int p;cin>>s>>p;
    pr[i]=make_pair(s,p);
    cnt+=p;
  }
  string x;cin>>x;
  int cnt1=0;
  rep(i,n){
    cnt1+=pr[i].second;
    if(x==pr[i].first)break;
  }
  cout<<cnt-cnt1<<endl;
}