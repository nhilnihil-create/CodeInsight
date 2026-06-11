#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {

  int n, bee;
  cin >> n;
  if(n == 1){
    cout << "1.0000000000";
  }else if(!(n % 2 == 0)){
    double ans;
    ans = double((n - 1) / 2 + 1) / double(n);
    cout << setprecision(10) << fixed << ans;
  }else{
    cout << "0.5000000000";
  }
  return 0;
}
