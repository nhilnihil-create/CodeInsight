#include<iostream>
#include<string>

using namespace std;
 
int main()
{
  int x1, x2, x3, x4, x5;
  cin >> x1 >> x2 >> x3 >> x4 >> x5;
  if(x1==0) cout << 1 << endl;
  else if(x1*x2==0) cout << 2 << endl;
  else if(x1*x2*x3==0) cout << 3 << endl;
  else if(x1*x2*x3*x4==0) cout << 4 << endl;
  else cout << 5 << endl;
}