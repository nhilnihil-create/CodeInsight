#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
  int n;
  double x[100], y[100];
  double dist1=0;
  double dist2=0;
  double dist3=0;
  double dist_inf=0;

  cin >> n;
  cout << fixed << setprecision(8);

  for(int i=0; i<n; i++){
    cin >> x[i];
  }
  for(int i=0; i<n; i++){
    cin >> y[i];
  }

  for(int i=0; i<n; i++){
    dist1 += abs(y[i] - x[i]);
  }
  cout << dist1 << endl;

  for(int i=0; i<n; i++){
    dist2 += pow(abs(y[i] - x[i]), 2.0);
  }
  dist2 = pow(dist2, 1/2.0);
  cout << dist2 << endl;


  for(int i=0; i<n; i++){
    dist3 += pow(abs(y[i] - x[i]), 3.0);
  }
  dist3 = pow(dist3, 1.0/3);
  cout << dist3 << endl;

  for(int i=0; i<n; i++){
    if(abs(y[i] - x[i])>dist_inf){
      dist_inf = abs(y[i] - x[i]);
    }
  }
  cout << dist_inf << endl;
}
