#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

int main(){
  int h,n;
  cin >> h >> n;

  int total = 0;
  rep(i,n) {
    int x;
    cin >> x;
    total += x;
  }
  if (total >= h) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
