#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
  int p[3];
  for(int i = 0; i < 3; i++)
    cin >> p[i];
 
  sort(p,p+3);
  cout << p[0]+p[1] << endl;
}