#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

vector< bool > isprime( 100000000, 1 );
int n, ret = 0;

int main()
{
    isprime[0] = isprime[1] = 0;
    for( int i = 2; i * i < 100000000; i++ )
    {
        if( isprime[i] )
        {
            for( int j = 1; i * ( j + 1 ) < 100000000; j++ )
            {
                isprime[ i * ( j + 1 ) ] = 0;
            }
        }
    }

    while( scanf( "%d\n", &n ) != EOF )
    {
        if( isprime[n] ){
            ret++;
        }
    }
    printf( "%d\n", ret );
    return 0;
}
