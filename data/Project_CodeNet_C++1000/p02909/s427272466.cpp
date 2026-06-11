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

const long INF = 1e9 + 1;

int main() {
  string s;
  cin >> s;

  if(s == "Sunny")
    cout << "Cloudy" << endl;
  else if(s == "Cloudy")
    cout << "Rainy" << endl;
  else cout << "Sunny" << endl;
}
