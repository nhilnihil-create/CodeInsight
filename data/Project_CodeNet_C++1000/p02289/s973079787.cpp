#include <queue>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
  priority_queue<int> Q;
  while (true) {
    int num;
    char oper[1000];
    scanf("%s", oper);
    if (oper[2]=='d') break;
    else if (oper[0]=='i') {
      scanf("%d", &num);
      Q.push(num);
    }
    else if (oper[1]=='x') {
      int ex = Q.top();
      Q.pop();
      cout << ex << endl;
    }
  }
}