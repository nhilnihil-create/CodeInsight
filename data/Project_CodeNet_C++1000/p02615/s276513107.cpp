#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
int main() {
  int n;
  priority_queue<ll> a;
  ll t,ans=0;
  cin>>n;
  rep(i,n){
    cin>>t;
    a.push(t);
    a.push(t);
  }
  a.pop();
  rep(i,n-1){
    ans+=a.top();
    a.pop();
  }
  cout<<ans;
}