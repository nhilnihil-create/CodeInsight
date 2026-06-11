#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define _LL long long

char _map[2000][2000];
int _xcount[2000][2000];
int _ycount[2000][2000];

int main()
{
    int h, w;
    cin >> h >> w;

    for(int y = 0; y < h; y++ )
    {
        string s;
        cin >> s;
        for( int x = 0; x < w; x++ )  _map[x][y] = (( s[x] == '.' ) ? 0 : 1);
    }

    for( int y = 0; y < h; y++ )
    {
        int prex = 0;
        for( int x = 0; x < w; x++ )
        {
            if( _map[x][y] == 1 )
            {
                int count = x - prex;
                for( int x2 = prex; x2 < x; x2++ ) _xcount[x2][y] = count;
                _xcount[x][y] = 0;
                prex = x + 1;
            }
        }
        {
            int count = w - prex;
            for( int x2 = prex; x2 < w; x2++ ) _xcount[x2][y] = count;
        }
    }

    for( int x = 0; x < w; x++ )
    {
        int prey = 0;
        for(int y = 0; y < h; y++ )
        {
            if( _map[x][y] == 1 )
            {
                int count = y - prey;
                for( int y2 = prey; y2 < y; y2++ ) _ycount[x][y2] = count;
                _ycount[x][y] = 0;
                prey = y + 1;
            }
        }
        {
            int count = h - prey;
            for( int y2 = prey; y2 < h; y2++ ) _ycount[x][y2] = count;           
        }
    } 

    int ans = 0;
    for( int x = 0; x < w; x++ )
    {
        for(int y = 0; y < h; y++ )
        {
            ans = max(ans, _xcount[x][y] + _ycount[x][y] - 1);
        }
    }
    cout << ans;
}