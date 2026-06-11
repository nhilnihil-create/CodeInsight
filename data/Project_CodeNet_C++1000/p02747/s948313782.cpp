#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s;
  cin >> s;
  string hitachi;
  for (int i; i < s.size(); i++){
  	hitachi += "hi";
	if (hitachi == s) {
      cout << "Yes" << endl;
      exit (0);
  }
 }
  cout << "No" << endl;
}