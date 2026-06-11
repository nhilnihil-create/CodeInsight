#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int d = N%10;
  
  if(d==2 || d==4 || d==5 || d==7 || d==9) cout << "hon"<< endl;
  else if (d == 3) cout << "bon" << endl;
  else cout << "pon" << endl;
}