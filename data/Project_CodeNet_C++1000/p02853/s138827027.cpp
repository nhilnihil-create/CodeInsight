#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int x,y,p;
  
  cin >> x >> y;
  
  p=0;
  if (x<=3) p+=(4-x)*100000;
  if (y<=3) p+=(4-y)*100000;
  
  if (x==1 && y==1) p+=400000;
  
  cout << p << endl;
  
  return 0;
}