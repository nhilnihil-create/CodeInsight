#include <bits/stdc++.h>
using namespace std;
 
int main() {
  double n,d,d2;
  int counter;
  cin >> n >> d;
  counter = 0;
  double x[200000],y[200000];
  for(int i = 0; i < n;i++){
      cin >> x[i] >> y[i];
  }

  d2 = d*d;

  for(int i = 0; i < n;i++){
    if (d2 >= (x[i]*x[i] + y[i]*y[i])) {
        counter++;
     }
  }

  cout << counter << endl;

}