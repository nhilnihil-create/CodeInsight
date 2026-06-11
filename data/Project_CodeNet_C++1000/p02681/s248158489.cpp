#include <iostream>
using namespace std;


int main(){
  string s, t;
  cin >> s >> t;
  cout << (t.substr(0, t.size() - 1) == s.substr(0, s.size()) ? "Yes" : "No")
    << endl;
}