#include <iostream>
#include <queue>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
  char cmd[2]; // command
  int digit; // digit to insert
  priority_queue<int> Q;
  while (true) {
    scanf(" %s", cmd);
    if (cmd[0] == 'e' && cmd[1] == 'n') break;
    if (cmd[0] == 'i') {
      scanf(" %d", &digit);
      Q.push(digit);
    } else {
      cout << Q.top() << endl;
      Q.pop();
    }
  }
}