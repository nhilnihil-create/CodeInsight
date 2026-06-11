#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
using namespace std;

int main(){
  int n,i,j;
  cin >> n;
  double x[n];
  double y[n];
  double d1,d2,d3,di=0;
  for(i = 0; i < 2; i++){
    for(j = 0; j < n; j++){
      if(i == 0) cin >> x[j];
      if(i == 1) cin >> y[j];
    }
  }
  for(i = 0; i < n; i++){
    d1 += pow(fabs(x[i] - y[i]), 1);
  }
  for(i = 0; i < n; i++){
    d2 += pow(fabs(x[i] - y[i]), 2);
  }
  for(i = 0; i < n; i++){
    d3 += pow(fabs(x[i] - y[i]), 3);
  }
  for(i = 0; i < n; i++){
    di = max( di, (double)abs(x[i] - y[i]) );
  }

  cout << fixed << setprecision(10) << pow(d1,1.0/1)   << endl;
  cout << fixed << setprecision(10) <<pow(d2,1.0/2)   << endl;
  cout << fixed << setprecision(10) <<pow(d3,1.0/3)   << endl;
  cout << fixed << setprecision(10) << di << endl;
}

