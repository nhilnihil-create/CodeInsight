#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)



int main() {
  int n,x;

  int ans = 1;

  cin >> n >> x;

  vector<int> l(n);

  rep(i,n){
    cin >> l.at(i);
  }
  int total = 0;

  rep(i,n){
    total += l.at(i);
    if(total<=x){
      // cout << total << endl;
      ans ++;

    }
  }

  cout << ans;


}