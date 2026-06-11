#include <bits/stdc++.h>
using namespace std;

int main(){
  string N;
  cin >> N;
  
  int n = N.size();
  char a;
  int b;
  int s = 0;
  for (int i=0 ; i<n ; i++){
    a = N.at(i);
    b = a - '0';
    s += b;
    s %= 9;
  }
  
  if (s == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}