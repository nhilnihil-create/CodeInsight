#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){
  int n,i;
  double m,a;
  cin >> n;
  int s[1000];
  while (n!=0) {
    m=0;
    for(i=0;i<n;i++) {
      cin >> s[i];
      m+=s[i];
    }
    m/=n;
    a=0;
    for(i=0;i<n;i++) {
      a+=pow(s[i]-m, 2);
    }
    a/=n;
    a=sqrt(a);
    cin >> n;
    cout << fixed;
    cout << std::setprecision(5) << a << endl;
  }
  return 0;
}

