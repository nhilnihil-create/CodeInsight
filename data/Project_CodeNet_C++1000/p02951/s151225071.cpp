#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >> A >> B >> C;
  int ans;
  ans= B + C - A;
  if(ans<0)
    ans=0;
  cout << ans;
}
