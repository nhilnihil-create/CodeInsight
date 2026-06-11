#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define _GLIBCXX_DEBUG
using ll = long long;

#define mod 1000000007

int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> A(n);
  rep(i,n){
    cin >> A[i].first;
    A[i].second = i+1;
  }

  sort(A.begin(), A.end());
  rep(i, n) cout << A[i].second << endl;

  return 0;
}
