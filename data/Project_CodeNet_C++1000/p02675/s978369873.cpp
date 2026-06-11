#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int n;
  cin >> n;

  switch(n % 10){
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
      cout << "hon" <<endl;
      break;
    case 0:
    case 1:
    case 6:
    case 8:
      cout << "pon" <<endl;
      break;
    case 3:
      cout << "bon" <<endl;
      break;
  }
}
