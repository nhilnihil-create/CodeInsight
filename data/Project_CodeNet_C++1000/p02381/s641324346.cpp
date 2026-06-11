#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
  double n, m, points[1000], sum, elSum;

  while(true){
    sum= 0;
    elSum = 0;
    cin >> n;
    if(n == 0) break;
    for(int i = 0; i < n; i++){
      cin >> points[i];
      sum += points[i];
    }

    m = sum / n;

    for(int i = 0; i < n; i++){
      elSum += pow(points[i] - m, 2);
    }
    cout << fixed << setprecision(6) << sqrt(elSum / n) << endl;
  }

  return 0;
}