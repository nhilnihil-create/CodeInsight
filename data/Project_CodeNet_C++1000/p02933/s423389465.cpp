#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ll long long int
using namespace std;

int main(void) {
  int a;
  string s;
  cin >> a >> s;
  
  if (a < 3200) {
    printf("red\n");
  } else {
    cout << s << endl;
  }
  return 0;
}
