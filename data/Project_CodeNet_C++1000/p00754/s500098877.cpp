// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1173&lang=jp

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// 方針：'('を見たら')'をStに入れる。'['を見たら']'をSに入れる。
// ']'を見たらStがemptyでなくtopが']'であることを確かめてpopする。
// ')'もおなじ。
// おかしくなったらその瞬間にno。だめでなければyes。
// ……ではなく、ダメでなかった場合は、Stが空ならyesである。

string S;

bool ok() {
  stack<char> St;
  for (unsigned int i=0; i<S.size(); i++) {
    switch(S[i]) {
    case '(':
      // cerr << S[i] << " pushed." << endl;
      St.push(')');
      break;
    case '[':
      // cerr << S[i] << " pushed." << endl;
      St.push(']');
      break;
    case ')':
      if (!St.empty() && St.top() == ')') {
	// cerr << S[i] << " popped." << endl;
	St.pop();
	break;
      } else {
	// cerr << "fails." << endl;
	return false;
      }
    case ']':
      if (!St.empty() && St.top() == ']') {
	// cerr << S[i] << " popped." << endl;
	St.pop();
	break;
      } else {
	// cerr << "fails." << endl;
	return false;
      }
    default: break;
    }
  }
  return St.empty();
}

int main() {
  while (getline(cin, S) && S != ".") {
    if (ok()) {
      printf("yes\n");
    } else {
      printf("no\n");
    }
  }
}