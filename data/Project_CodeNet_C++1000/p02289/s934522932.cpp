#include<queue>
#include<iostream>
#include<string>
using namespace std;
int main() {
  priority_queue<int> Q;
  string str;
  while(cin >> str){
    if (str == "insert"){
      int x;
      cin >> x;
      Q.push(x);
    }
    else if (str == "extract"){
      cout << Q.top() << endl;
      Q.pop();
    }
  }
}