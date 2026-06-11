#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string s, p;
  cin >> s >> p;
  s.append(s);
  if (s.find(p) != string::npos)
    printf("Yes\n");
  else
    printf("No\n");
  return 0;
}