#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  a -= b*2;
  cout << max(0,a) << endl;
}