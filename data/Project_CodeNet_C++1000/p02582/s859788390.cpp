#include <iostream>

using namespace std;

int main(){
  string S;
  cin >> S;
  if (S == "RRR")
    cout << "3" << endl;
  else if (S == "SRR" || S == "RRS")
    cout << "2" << endl;
  else if (S == "RSR"|| S == "SSR" || S == "RSS" || S == "SRS")
    cout << "1" << endl;
  else
    cout << "0" << endl;
  return 0;
}