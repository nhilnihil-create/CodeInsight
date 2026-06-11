#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;

  cin >> n;
  while (n != 0){
    stack<int> a, b;
    int s[10];
    bool judge = true, j = false;
    for (int i = 0; i < 10; i++){
      cin >> s[i];
    }
    a.push(s[0]);
    for (int i = 1; i < 10; i++){
      if (a.top() < s[i]){
        a.push(s[i]);
      }
      else if (!j){
        b.push(s[i]);
        j = true;
      }
      else if (b.top() < s[i]){
        b.push(s[i]);
      }
      else {
        judge = false;
        break;
      }
    }

    if (judge){
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
    n--;
  }
}