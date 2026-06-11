#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  int a, b, c;
  //cin >> a;
  double ans, ra, rb;
  string weatherReport;
  cin >> weatherReport;
  if(weatherReport == "Sunny"){
    cout << "Cloudy";
  }else if(weatherReport == "Cloudy"){
    cout << "Rainy";
  }else{
    cout << "Sunny";
  }
  return 0;
}
