#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int n;cin>>n;
  vector<int> a(n);
  int cnt=0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  if(i%2==1&&a[i]%2==1)cnt++;
  }
  cout<<cnt<<endl;
}
