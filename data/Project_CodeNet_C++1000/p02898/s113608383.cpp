#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n,k;

  cin >> n >> k;

  int flag = 0;

  vector<int> h(n);

  rep(i,n){
    cin >> h.at(i);
    if(k<=h.at(i))
    flag ++;
  }

  cout << flag ;


}
