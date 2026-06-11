#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main(){

  vector<int> x,y;
  int n;
  int temp;
  double p1 = 0;
  double p2 = 0;
  double p3 = 0;
  double p4 = 0;

  cin >> n;
  for( int i = 0; i < n; ++i){
    cin >> temp;
    x.push_back(temp);
  }
  for( int i = 0; i < n; ++i){
    cin >> temp;
    y.push_back(temp);
  }
    
  for( int i = 0; i < n; ++i){
    p1 += abs(x[i]-y[i]);
    p2 += (x[i]-y[i])*(x[i]-y[i]);
    p3 += fabs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]));
    if( p4 < abs(x[i]-y[i]) ){
      p4 = abs(x[i]-y[i]);
    }
  }

  p2 = sqrt(p2);
  p3 = cbrt(p3);

  cout << fixed << setprecision(5) << p1 << endl << p2 << endl << p3 << endl << p4 << endl;
  return 0;
  
}