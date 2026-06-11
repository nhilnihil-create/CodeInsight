#include <cstdio>
#include <iostream>

using namespace std;


signed main()
{   
    int mp[101] = {0};
    int key;
    while ( scanf("%d\n", &key ) != EOF )
    {
        mp[ key ]++;
    }
    int mode = 0;
    for( int i = 1; i <= 100; i++ )
    {
        if( mode < mp[i] )
        {
            mode = mp[i];
        }
    }
    
    ///mode_value
    for( int i = 1; i <= 100; i++ )
    {
        if( mp[i] == mode )
        {
            printf( "%d\n", i );
        }
    }
    return 0;
}
