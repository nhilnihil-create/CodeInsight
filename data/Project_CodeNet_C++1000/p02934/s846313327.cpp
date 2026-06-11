#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int n;
  double bubble, pliefsto, gappy;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> pliefsto;
    gappy = gappy + 1 / pliefsto;

  }
  bubble = 1 / gappy;
  cout << fixed << setprecision(10) << bubble;
  return 0;
}
