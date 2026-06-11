#include <bits/stdc++.h>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
using namespace std;
using ll = long long;
using d = double;

int main(){
  int n,k;
  cin >> n >> k;
  int a[n] = {0};
  rep(i,k){
    int d;
    cin >> d;
    rep(j,d){
      int s;
      cin >> s;
      if(a[s-1]==0)++a[s-1];
    }
  }
  int ans=0;
  rep(i,n){
    if(a[i]==0)++ans;
  }
  cout << ans << endl;
  return 0;
}