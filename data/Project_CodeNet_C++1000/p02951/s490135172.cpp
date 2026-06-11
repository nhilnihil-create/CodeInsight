#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;  
  if(b+c <= a) cout << "0" << endl;
  else cout << c-(a-b) << endl;
}