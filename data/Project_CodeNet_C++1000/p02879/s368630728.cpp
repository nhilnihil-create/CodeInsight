#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B;
  cin >> A >> B;

  int ans= (A >= 10 || B >= 10) ? -1
                                : A* B;

  cout << ans << endl;
}