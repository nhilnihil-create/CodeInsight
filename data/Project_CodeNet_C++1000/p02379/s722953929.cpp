#include<iostream>
#include<cmath>
#include <iomanip>

using namespace std;

int main(){
  double x1,y1,x2,y2;

  long double ans;

  cin >> x1 >> y1 >> x2 >> y2;
  
  ans = sqrt(pow(x2-x1,2)+pow(y2-y1,2));

  cout << fixed << setprecision(5) << ans << endl;
}
  