#include<bits/stdc++.h>
using namespace std;
int main() {
  int n; cin >> n;
  vector<int> aivector(n);
  priority_queue<int> aiqueue;
  for(int &c : aivector) {
    cin >> c;
    aiqueue.push(c);
  }
  for(int i = 0; i < n; i++) {
    if(aivector.at(i) == aiqueue.top()) {
      int save = aiqueue.top();
      aiqueue.pop();
      cout << aiqueue.top() << endl;
      aiqueue.push(save);
    }
    else {
      cout << aiqueue.top() << endl;
    }
  }
}