#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  int n;
  cin >> n;
  int i;
  double x = 0;
  for(i=0;i<n;i++){
    double a;
    cin >> a;
    x += 1/a;
  }
  cout << fixed << setprecision(20) << 1/x << "\n";
  return 0;
}