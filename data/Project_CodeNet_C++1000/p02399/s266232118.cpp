#include <iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
   long a=0,b=0,c=0,i=0;
   double f =0.000000000000;
        cin >> a;
        cin >> b;
        c = a/b;
        i = a%b;
        f = (double)a/(double)b;
   cout << c << " " << i << " ";
   cout << fixed;
   cout.precision(16);
   cout << (double)(f) << endl;


}