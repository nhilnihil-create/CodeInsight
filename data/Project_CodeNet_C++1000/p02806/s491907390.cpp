#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> a(55);
  vector<string> s(55);
  rep(i,n)cin>>s[i]>>a[i];
  string x;cin>>x;
    int cnt=0;
    for(int i=n-1;i>=0;i--){
      if(x==s[i])break;
      cnt+=a[i];
    }
    cout<<cnt<<endl;
}