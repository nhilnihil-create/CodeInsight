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
    if (cmd[0] == 'i') { // if command is insert
      scanf(" %d", &digit);
      Q.push(digit);
    } else { // if command starts with 'e'
      if (cmd[1] == 'n') break; //if command is 'end'
      printf("%d\n", Q.top());
      Q.pop();
    }
  }
}