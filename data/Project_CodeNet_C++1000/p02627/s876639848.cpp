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
  char A;
  cin >> A;
  if(isupper(A)){
    cout << "A" <<endl;
  } else{
    cout << "a" <<endl;
  }
}