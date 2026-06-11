#include <functional>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;


int main() {
   int n;
 
   cin >> n;
  
   double a[n];
  
  double sum = 0;
  for(int i = 0;i<n;i++){
     
    cin >> a[i];
    
    sum = sum + 1/a[i];

   }
  
  
  cout << 1/sum << endl;
   
  return 0;
}