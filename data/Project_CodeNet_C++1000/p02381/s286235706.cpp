#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
 
int main()
{
  int n;
  int *mark;
  double mean,sig;

  while (1){
    cin >> n;
    if( n==0 ){
      break;
    }
    
    double sum=0;
    double sig=0;
    
    mark = new int [n];
    for (int i=0; i<n; i++){
      cin >> mark[i];
      sum += mark[i];
    }
    mean = sum/n;
    
    for (int i=0; i<n; i++){
      sig += pow(mark[i] - mean, 2.0);
    }
    sig = sqrt( sig/n );
    
    
    cout << fixed
      << setprecision(5)
        << sig
          << endl;

    delete [] mark;
    
  }
  
  return(0);
}