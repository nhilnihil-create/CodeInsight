#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;

  cin >> n;

  int a;

  // vector<int> a(n);

  vector<int> buka(n,0);

  rep(i,n-1){
    cin >> a;
    buka.at(a-1) += 1;

  }

  rep(i,n){
    cout << buka.at(i) << endl;

  }

}