using namespace std;
#include <iostream>
#include <string>

int main(){
  int N;
  cin >> N;
  
  int AC = 0, WA = 0, TLE = 0, RE = 0;
  string judge;
  
  for (int i = 0; i < N; i++){
    cin >> judge;
    if (judge == "AC") AC += 1;
    if (judge == "WA") WA += 1;
    if (judge == "TLE") TLE += 1;
    if (judge == "RE") RE += 1;
  }

  cout << "AC x " << AC << endl;
  cout << "WA x " << WA << endl;
  cout << "TLE x " << TLE << endl;
  cout << "RE x " << RE;

  return 0;
}