#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int month1, month2;
  int day1, day2;
  int result = 0;
 
  cin >> month1 >> day1;
  cin >> month2 >> day2;
  
  if (day2 == 1) {
    result = 1;
  }
 
  cout <<result << endl;
}