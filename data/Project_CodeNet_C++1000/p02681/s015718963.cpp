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
  string S, T;
  cin >> S >> T;
  if(T.substr(0, S.size()) == S){
    cout << "Yes"<<endl;
  }
  else {
    cout << "No" <<endl;
  }
}
