#include<bits/stdc++.h>
using namespace std;

int main(){
  int X;
  cin >> X;
  cout << 9 - (X - X % 200 - 200) / 200 << endl;
}