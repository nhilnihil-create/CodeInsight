#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int A, B, C, D;
  cin >> A >> B >> C;
  D=min((A+B),(B+C));
  cout << min((C+A),D) << endl;
}
