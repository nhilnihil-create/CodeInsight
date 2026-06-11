#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x ;
  int c500 = x/500;
  int r500 = x%500;
  int c5 = r500/5;
  cout << c500*1000+c5*5;
}