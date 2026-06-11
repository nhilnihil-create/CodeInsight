#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i, n) cin>>a.at(i);
  
  int ans = 0;
  int f = 1;
  rep(i, n){
    if(a.at(i)==f){
      f++;
    }
    else{
      ans++;
      if(ans==n) ans=-1;
    }
  }
  cout<<ans<<endl;
}