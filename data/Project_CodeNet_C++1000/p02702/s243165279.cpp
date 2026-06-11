#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int p1[2019];
    int p2[2019];
    for( int i = 0; i < 2019; i++) p1[i] = 0;
    for( int i = 0; i < 2019; i++) p2[i] = 0;
    int *current = p1;
    int *next = p2;
    int ans = 0;
    {
        char c = getchar();
        int n = c - '0';
        current[n] = 1;
    }

    while(true)
    {

        char c = getchar();
        if( c < '1' || c > '9' ) break;
        int n = c - '0';
        for( int i = 0; i < 2019; i++ ) next[i] = 0;
        next[n] = 1;
        for( int i = 0; i < 2019; i++ )
        {
            int nmod = (10 * i + n) % 2019;
            next[nmod] += current[i];
        }
        ans += next[0];

        if( current == p1 )
        {
            current = p2;
            next = p1;
        }
        else
        {
            current = p1;
            next = p2;
        }
    }

    cout << ans;

    return 0;    
}