#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    double n,d;
    cin >>n>>d;
    int ko = 0;
    for(int i = 0;i<n;i++){
      long x,y;
      cin >>x>>y;
      double k = pow(x*x+y*y,0.5);
      if(k<=d) ko++;
    }
 	cout<<ko;
    return 0;
}