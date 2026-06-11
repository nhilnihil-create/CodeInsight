#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int a[1001],n=-1;
  
  for( ; ; ){
    cin >> n;
    if(n==0) break;
    int sum=0;
    double avg=0,sumh=0;
    
    for(int i=0;i<n;i++){
      cin >> a[i];
      sum +=a[i];
    }
    avg=(double)sum/n;
    
    for(int i=0;i<n;i++){
      sumh += (double) (a[i]-avg)*(a[i]-avg);
    }
    cout.precision(10);
    cout << sqrt(sumh/n) << endl;
    
    n=-1;
  }
  return 0;
}