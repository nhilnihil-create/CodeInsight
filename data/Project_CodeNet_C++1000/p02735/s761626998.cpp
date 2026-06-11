#include <bits/stdc++.h>
#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
    int h, w;
    cin >> h;
    cin >> w;

    char *initmap = (char*) malloc(h * w);
    int *changennum = (int*) malloc(h * w * sizeof(int));

    {
        string s;
        getline(cin,s); // 改行読み飛ばし

        for(int r = 0; r < h; r++)
        {
            getline(cin,s);
            for( int c = 0; c < w; c++)
            {
                if (s[c] == '.') 
                {
                    initmap[r * w + c] = 1;
                }
                else
                {
                    initmap[r * w + c] = 0;
                }        
            }
        }
    }

    changennum[0] = (initmap[0] == 1) ? 0 : 1;

    for( int d = 1; d < h + w - 1; d++)
    {
        for( int r = 0; r < d + 1 && r < h; r++)
        {
            int c = d - r;
            if( c >= w ) continue;
            int ans = h + w;
            if( c > 0 )
            {
                int tmp = changennum[ r * w + (c - 1) ];
                if( initmap[r * w + c] != initmap[r * w + (c - 1) ] ) tmp++;
                ans = tmp;
            }

            if( r > 0 )
            {
                int tmp = changennum[ (r - 1) * w + c ];
                if( initmap[r * w + c] != initmap[(r - 1) * w + c ] ) tmp++;
                if( tmp < ans ) ans = tmp;
            }

            changennum[ r * w + c ] = ans;
        }
    }

    cout << (changennum[ h * w - 1 ] + 1) / 2;

    free(initmap);
    free(changennum);
}