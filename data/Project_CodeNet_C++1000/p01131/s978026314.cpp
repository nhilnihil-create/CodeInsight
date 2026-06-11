#include <iostream>
#include <string>

using namespace std;

string chars[] = {
  "",
  ".,!? ",
  "abc",
  "def",
  "ghi",
  "jkl",
  "mno",
  "pqrs",
  "tuv",
  "wxyz",
};

int main() {
  int nnn;
  cin >> nnn;
  for (int iii = 0; iii < nnn; ++iii) {
    string input;
    cin >> input;
    int prev = 0, cnt = 0;
    for (char c : input) {
      int i = c-'0';
      if (i == 0) {
	if (prev != 0) {
	  cout << chars[prev][(cnt-1) % chars[prev].size()];
	}
	prev = i;
	cnt = 0;
      } else {
	prev = i;
	++cnt;
      }
    }
    cout << endl;
  }
}