#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> h(n);
  rep(i,n)cin>>h[i];
  int cnt=0;;
  rep(i,n){
    if(cnt<h[i])h[i]--;
    if(cnt>h[i]){
      cout<<"No"<<endl;
      return 0;
    }
    cnt=max(cnt,h[i]);
  }
  cout<<"Yes"<<endl;
}