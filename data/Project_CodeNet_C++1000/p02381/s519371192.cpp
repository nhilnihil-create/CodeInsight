#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
  int n,i;
  double sum, average;
  double s2;
  cin >> n;
  while(n != 0){
    int student[n];
    sum = 0;
    average = 0;
    s2 = 0;
    for(i = 0; i < n; i++){
      cin >> student[i];
      sum += student[i];
    }
    average = sum/n;
    for(i = 0; i < n; i++){
      s2 += pow((student[i] - average) , 2);
    }
    s2 = s2/n;
    cout << fixed << setprecision(16) << sqrt(s2) << endl;
    cin >> n;
  }
}

