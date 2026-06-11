#include <iostream>
using namespace std;

int gcd(int n,int m){
  if(n%m==0) return m;
  else gcd(m,n%m);
}

int main()
{
  int x,y,g;
  cin >> x >> y;
  
  if(x==y) g=x;
  else if(x>y) g=gcd(x,y);
  else g=gcd(y,x);
  cout << g << endl;

  return 0;
}