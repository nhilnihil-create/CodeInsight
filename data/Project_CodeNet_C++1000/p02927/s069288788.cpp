#include <iostream>
#include <math.h>
using namespace std;

int main()
{
   int m, d;
   cin >> m;
   cin >> d;
   int cifra1, cifra2;
   int numar = 0;
   for (int i = 4; i <= m; i++)
   {
       for (int j = 22; j <= d; j++)
       {
           cifra1 = j % 10;
           cifra2 = j / 10;
           if (cifra1 * cifra2 == i && cifra1 != 1 && cifra2 != 1)
           {
               numar++;
           }
       }
   }
   cout << numar;

    return 0;
}
