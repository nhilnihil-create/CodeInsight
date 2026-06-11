#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <utility>
#include <cctype>
#include <numeric>
using namespace std;

#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define foreach(c,i) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

int main() {
  string line;
  while (getline(cin, line)) {
    if (line == ".") break;
    stack<char> s;
    const int N = line.size();
    bool ok = true;
    
    rep(i,N) {
      if ((line[i] == '[') || (line[i] == '(')) {
        s.push(line[i]);
      } else if (line[i] == ']') {
        if (s.size() && s.top() == '[') {
          s.pop();
        } else {
          ok = false; break;
        }
      } else if (line[i] == ')') {
        if (s.size() && s.top() == '(') {
          s.pop();
        } else {
          ok = false; break;
        }
      }
    }

    if (s.size()) ok = false;
    
    printf("%s\n", ok ? "yes" : "no");
  }
  return 0;
}