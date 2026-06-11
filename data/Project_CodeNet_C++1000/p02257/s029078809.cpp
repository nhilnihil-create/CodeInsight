#include<iostream>
#include<cmath>
using namespace std;


bool PrimeNumbers2( int x )
{
    for( int i = 2; i <= sqrt(x); i++)
    {
        if( x % i == 0 )
            return false;
    }
    return true;
}


int main() 
{
    int num;
    int count = 0;                      //素数の数をカウントする

    while( cin >> num )
    {
        if( PrimeNumbers2(num) )
            count++;
    }

    cout << count << endl;

    return 0;
}
