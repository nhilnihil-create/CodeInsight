/*
 * Problem     : AOJ1173
 * Title       : The Balance of the World (世界の天秤)
 * Author      : mizo0203
 * Copyright   : Your copyright free
 * Description : 文字列・スタック
 */

#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;

char str[101];
stack<char> st;

bool input() {
  scanf("%[^\n]%*c", str);
  if (str[0] == '.')
    return false;
  return true;
}

int main() {
  int i;
  bool f;

  while (input()) {
    f = true;
    while(!st.empty()) st.pop();
    for (i = 0; str[i] != '\0' && f; i++) {
      switch (str[i]) {
      case '(':
        st.push(')');
        break;
      case ')':
        if (!st.empty() && st.top() == str[i])
          st.pop();
        else
          f = false;
        break;
      case '[':
        st.push(']');
        break;
      case ']':
        if (!st.empty() && st.top() == str[i])
          st.pop();
        else
          f = false;
        break;
      default:
        break;
      }
    }
    if (st.empty() && f)
      printf("yes\n");
    else
      printf("no\n");
  }

  return 0;
}