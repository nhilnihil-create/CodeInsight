#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  int cnt=1,ans=a[0];
  for(int i=1;i<n;i++){
    if(a[i]<ans){
      ans=a[i];
      cnt++;
    }
  }
  cout<<cnt<<endl;
}