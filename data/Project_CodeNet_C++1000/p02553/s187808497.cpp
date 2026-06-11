#include <iostream>
using namespace std;
int main()
{
    long long  a = 0,b = 0,c = 0,d = 0;
   long long max = 0;
    cin >> a >> b >> c >> d;
    max = a * c;
    if (max < a * d)
        max = a * d;
    if (max < b * d)
        max = b * d;
    if (max < b * c)
        max = b * c;
    cout << max << endl;

   
}