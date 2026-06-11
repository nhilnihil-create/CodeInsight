#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
using T = tuple<string,int,int>;

int main(){
  int n,d; cin >> n >> d;
  int k = 1 + d + d;
  int ans = (n+k-1) / k;
  cout << ans << endl;
  return 0;
}