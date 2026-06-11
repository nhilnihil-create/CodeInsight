#include <iostream>
using namespace std;
 
int main()
{
    int multiplier,multiplicand;
 
    for( multiplicand = 1; multiplicand < 10 ; multiplicand++)
    {
       for(multiplier = 1; multiplier < 10 ; multiplier++)
           cout << multiplicand << "x" << multiplier << "=" << multiplicand * multiplier << endl;
    }
 
    return 0;
}