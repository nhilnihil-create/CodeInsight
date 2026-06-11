# include <iostream>
using namespace std;
 
int main(void){

  int a, b, c, x, y, z;
  a = b = c = x = y = z = 0;

  cin >> a >> b >> c;
 
  if(a > b){ x = a; a = b; b = x;}
  if(b > c){ y = b; b = c; c = y;}
  if(a > b){ z = a; a = b; b = z;}
 
  cout << a << " " << b << " " << c << endl;
 
  return 0;
 
}