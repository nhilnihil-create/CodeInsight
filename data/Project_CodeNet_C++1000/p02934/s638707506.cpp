#include <iostream>
#include <iomanip>
using namespace std;
int main(){
  int n;
  cin >> n;
  double a, s=0.0;
  for(int i=0; i<n; i++){
    cin >> a;
    s+=1/a;
  }
  cout << fixed << setprecision(6) << 1/s;
  return 0;
}