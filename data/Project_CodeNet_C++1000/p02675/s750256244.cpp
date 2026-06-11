#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  n %= 10;
  string s = "hon";
  if(n == 3)
    s = "bon";
  if(n == 0 || n == 1 || n == 6 || n == 8)
    s = "pon";
  cout << s << endl;
}