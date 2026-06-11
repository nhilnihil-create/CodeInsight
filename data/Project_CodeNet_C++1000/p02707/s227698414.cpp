#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < n;i++)
typedef long long ll;
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> a(n-1);
  rep(i, n - 1){
    cin >> a[i];
  }

  vector<int> tmp(n);
  rep(i, n - 1){
    tmp[a[i] - 1] += 1;
  }

  rep(i, n){
    cout << tmp[i] << endl;
  }
}