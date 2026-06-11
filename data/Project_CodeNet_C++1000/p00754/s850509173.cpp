#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;

  while(getline(cin, s)) {
    if(s[0] == '.') break;
    bool b = true;
    int x = 0, y = 0;
    char c[1000];
    int top = 0;

    for(int i = 0; i < s.size(); i++) {
      if(s[i] == '(') {
	x++;
	c[top] = s[i];
	top++;
      }
      else if(s[i] == ')') {
	x--, top--;
	if(c[top] != '(') {
	  //cout << c[top] << ' ' << s[i] << endl;
	  b = false;
	  break;
	}
      }
      else if(s[i] == '[') {
	y++;
	c[top] = s[i];
	top++;
      }
      else if(s[i] == ']') {
	y--, top--;
	if(c[top] != '[') {
	  //cout << c[top] << ' ' << s[i] << endl;
	  b = false;
	  break;
	}
      }
      if(x < 0 || y < 0) {
	//cout << x << ' ' << y << endl;
	b = false;
	break;
      }
    }
    if(x == 0 && y == 0 && b) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}