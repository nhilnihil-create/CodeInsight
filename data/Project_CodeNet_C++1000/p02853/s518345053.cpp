#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  vector<int> v = {300000,200000,100000};
  int money;

  money = v[a-1] + v[b-1];
  if(a == 1 && b == 1) money += 400000;
  cout << money << endl;

}