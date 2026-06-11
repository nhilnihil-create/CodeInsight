#include <iostream>
using namespace std;


int main () {

 int a,b,c;
 cin >> a >> b >> c;

  int temp =0;
  
  temp=a;
  a=b;
  b=temp;
  
  temp=a;
  a=c;
  c=temp;
  
  cout << a << " " << b << " " << c;
 
	return 0;
}
