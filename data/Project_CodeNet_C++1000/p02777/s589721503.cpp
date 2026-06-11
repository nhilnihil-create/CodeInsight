#include <bits/stdc++.h>
using namespace std;

int main() {
  string a;
  string b;
  int c;
  int d;
  string e;
  
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  cin >> e;
  
  if (a == e) {
    cout << c - 1;
    cout << " ";
    cout << d;
    return 0;
  }
    
  cout << c;
  cout << " ";
  cout << d - 1;
    
  return 0;   
}