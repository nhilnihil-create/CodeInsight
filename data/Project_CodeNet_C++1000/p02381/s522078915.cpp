#include <iostream>
#include <cmath>
#include <iomanip>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;


int main(void){
  int n;
  double s[1500];
  double ave;
  double alpha;

  while(1){
    ave = 0;
    alpha = 0;
    cin >> n;
    if(n == 0){
      break;
    }
    for(int i=0;i < n;i++){
      cin >> s[i];
      ave += s[i];
    }

    ave /= n;
    cout << fixed;
    for(int i = 0;i < n;i++){
      alpha += (ave-s[i])*(ave-s[i]);
    }

    alpha = sqrt(alpha/n);
    cout << setprecision(10) <<  alpha << endl;
  }
}