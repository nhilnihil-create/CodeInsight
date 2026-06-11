#include <iostream>
#include <queue>
#include <string>
#include <utility>

using namespace std;

typedef pair<string, char> P;

int n;
queue<P> q;

int main() {
  cin >> n;
  
  q.push(P("a", 'a'));
  
  while (q.size()) {
    P p = q.front();
    q.pop();
    string s = p.first;
    char ch = p.second;
    if (s.length() == n) {
      cout << s << endl;
      continue;
    }
    for (char c = 'a'; c <= ch; c++) {
      q.push(P(s+c, ch));
    }
    ch++;
    q.push(P(s+ch, ch));
  }
  
  return 0;
}