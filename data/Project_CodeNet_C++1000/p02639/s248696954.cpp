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
  vector<int> vec(5);
  for(int i = 0; i < 5; i++){
    cin >> vec[i];
    if(vec[i] == 0){
      cout << i+1 <<endl;
      return 0;
    }
  }
}