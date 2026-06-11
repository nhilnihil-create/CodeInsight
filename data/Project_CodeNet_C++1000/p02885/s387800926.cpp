#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int a,b;
  cin>>a>>b;
  
  int ans = a -2*b;
  
  if(ans>=0) {
    cout<<ans;
  } else {
    cout<<0;
  }
}