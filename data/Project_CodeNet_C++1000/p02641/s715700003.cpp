#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int x,n;cin>>x>>n;
  vector<int> vec(102);
  rep(i,n){
    int p;cin>>p;
    vec[p]++;
  }
  int ans,cnt=1e9;
  rep(i,102){
    if(vec[i]==0&&cnt>abs(x-i)){
      ans=i;
      cnt=abs(x-i);
    }
  }
  cout<<ans<<endl;
}