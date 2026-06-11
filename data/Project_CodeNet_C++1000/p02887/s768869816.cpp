#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  string s;cin>>s;
  int cnt=1;
  rep(i,n-1){
    if(s[i]==s[i+1])continue;
    cnt++;
  }
  cout<<cnt<<endl;
}