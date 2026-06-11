#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main() {
  int l, f;
  string S;
  stack<int> T;
  while (getline(cin, S), S != ".") {
    l = S.size();
    f = 1;
    for (int i = 0; i < l; ++i) {
      if (S[i] ==  '(' || S[i] == '[') T.push(S[i]);
      else if (S[i] == ')') {
	if (T.empty() || T.top() != '(') {
	  cout << "no" << endl;
	  f = 0;
	  break;
	}
	T.pop();
      }else if (S[i] == ']') {
	if (T.empty() || T.top() != '[') {
	  cout << "no" << endl;
	  f = 0;
	  break;
	}
	T.pop();
      }
    }
    if (f) {
      if (T.empty()) {
	cout << "yes" << endl;
      } else {
	cout << "no" << endl;
      }
    }
    while (!T.empty()) T.pop();
  }
  return 0;
}