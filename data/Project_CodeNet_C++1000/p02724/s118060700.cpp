#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int x, joy = 0;
  cin >> x;
  joy += (x/500)*1000;
  x = x%500;
  joy += (x/5)*5;
  cout << joy << endl;
}