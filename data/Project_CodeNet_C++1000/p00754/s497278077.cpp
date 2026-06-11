#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

const int INF = 1 << 28;

int main()
{
  for(;;) {
    string str;
    getline(cin, str);

    if(str == ".") {
      break;
    }

    stack<int> list;
    int pl = 0;
    int kl = 0;
    bool flag = true;
    for(char c : str) {
      switch (c) {
        case '(':
          ++pl;
          list.push(0);
          break;
        case '[':
          ++kl;
          list.push(1);
          break;
        case ')':
          flag &= pl > 0;
          if(flag) {
            flag &= list.top() == 0;
            list.pop();
          }
          --pl;
          break;
        case ']':
          flag &= kl > 0;
          if(flag) {
            flag &= list.top() == 1;
            list.pop();
          }
          --kl;
          break;
      }
    }
    flag &= pl == 0;
    flag &= kl == 0;

    cout << (flag ? "yes" : "no") << endl;
  }

  return 0;
}