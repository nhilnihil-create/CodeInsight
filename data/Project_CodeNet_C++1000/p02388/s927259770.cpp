#include <iostream>
using namespace std;
  
int main()
{
   int x,cx;
   cin >> x;
  
   cx = x;
   for(int i = 0; i < 2 ; i++)
   {
       x = x*cx;
   }
 
   cout << x << endl;
  
   return 0;
}