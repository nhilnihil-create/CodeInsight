#include <iostream>
using namespace std;
 
int main() {
  long int x;
  cin>>x;
  
  long int sum=0,a=100;
  
    while(x > a){
      a += a/100;
      sum+=1;
    }
   cout << sum << endl;
  return 0;
  
}