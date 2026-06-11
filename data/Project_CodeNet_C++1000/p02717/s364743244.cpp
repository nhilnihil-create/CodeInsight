#include <iostream>
using namespace std;

//int main(int argc, char **argv)
int main()
{   
  int a, b, c, x, y, z;  
  //a = stoi(argv[1]);
  //b = stoi(argv[2]);
  //c = stoi(argv[3]);
  cin >> a >> b >> c;
  x = a;
  y = b;
  z = c;
  a = y;
  b = x;
  x = a;
  y = b;
  z = c;
  a = z;
  c = x;

  cout << a << " " << b << " " << c << endl;
  return 0;
}
