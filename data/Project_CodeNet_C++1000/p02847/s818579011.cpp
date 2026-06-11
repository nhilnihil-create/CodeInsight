#include <iostream>
#include <string>

using namespace std;

int main() {
  string S;
  cin >> S;
  int result = 0;
  if (S == "SUN") result = 7;
  else if (S == "MON") result = 6;
  else if (S == "TUE") result = 5;
  else if (S == "WED") result = 4;
  else if (S == "THU") result = 3;
  else if (S == "FRI") result = 2;
  else if (S == "SAT") result = 1;
  cout << result << endl;
  return 0;
}
