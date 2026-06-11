#include <iostream>
using namespace std;

int gcd(int a, int b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

int main() {
  int N;
  cin >> N;
  cout << 360/gcd(360,N) << endl; 
}
