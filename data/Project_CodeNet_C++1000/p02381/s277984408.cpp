#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  double m;
  int n;

  while(true){
    cin>>n;
    if(n==0)break;
    double s[1000] = {};
    m = 0;
    for(int i=0; i<n; i++){
      cin >> s[i];
      m+=s[i];
    }
    m/=n;

    double sum_sq=0;
    for(int i=0; i<n; i++){
      sum_sq += pow(s[i] - m, 2);
    }
    cout << fixed << setprecision(8);
    cout << sqrt(sum_sq/n) << endl;
    }
}
