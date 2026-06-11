#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  double *x,*y;
  double p1 = 0,p2 = 0,p3 = 0,p = 0;

  cin >> n;
  
  x = new double[n];
  y = new double[n];


  
  for(int i = 0; i<n; ++i) cin >> x[i];
  for(int i = 0; i<n; ++i) cin >> y[i];
  
  double work;
  for(int i=0; i<n; ++i){
    work = abs(x[i] - y[i]);
    p1 += work;

    p2 += work * work;

    p3 += work * work * work;

    p = max(p,work);
  }

  p2 = sqrt(p2);
  p3 = pow(p3,1.0/3);

  cout << fixed << setprecision(12) << p1 << endl << p2 << endl << p3 << endl << p << endl;

  delete[] x;
  delete[] y;
}

