#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  queue<string> w;
  w.push("a");
  while(w.front().size()<n) {
    char maxchar='a';
    for(int i=1;i<w.front().size();i++) maxchar=max(maxchar,w.front().at(i));
    maxchar++;
    for(char charplus='a';charplus<=maxchar;charplus++) w.push(w.front()+charplus);
    w.pop();
  }
  while(w.size()!=0) {
    cout << w.front() << endl;
    w.pop();
  }
}