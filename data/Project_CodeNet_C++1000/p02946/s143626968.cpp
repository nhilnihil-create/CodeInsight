#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  int k,x;
  cin >> k >> x;
  int l=max(-1000000,x-k+1);
  int r=min(1000000,x+k-1);
  for(int i=l; i<=r; i++) {
    cout << i << " ";
  }
}
