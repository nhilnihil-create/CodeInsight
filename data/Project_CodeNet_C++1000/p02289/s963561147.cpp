#include <queue>
#include <iostream>
using namespace std;

int main() {
  string word;
  priority_queue<int> Q; // int を格納する優先度つきキュー
  while (cin >> word) { // 入力がある限り読み込む
    if (word == "insert") {
      int n;
      cin >> n;
      Q.push(n);
    }
    else if (word == "extract") {
      int n = Q.top();
      cout << Q.top() << endl;
      Q.pop();
    }
    else if (word == "end") {
      break;
    }
  }
}
