#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <math.h>
#include <stack>
#include <string>
#include <string.h>
using namespace std;
double PI = 3.1415926535897932;
long mod = 1000000007;

const long INF = (1<<30);

int main() {
  int a,b;
  cin >> a >> b;
  
  for(int i = b * 10; i < (b+1)*10; i++) {
    if((int)(i * 0.08) == a) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl; 
}