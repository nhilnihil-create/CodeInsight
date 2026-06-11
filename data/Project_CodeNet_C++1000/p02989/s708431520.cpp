// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for (int i = 0; i < n; ++i)
#define repr(i,n) for (int i = n; i > 0; --i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int MAX = 100;
const int INF = (1<<12);

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i,n){
    cin >> A[i];
  }
  
  sort(A.begin(), A.end());

  int ans = A[A.size()/2] - A[A.size()/2 -1];
  cout << ans << endl;
  return 0;
}