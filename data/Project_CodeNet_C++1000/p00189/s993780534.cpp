#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int v, s, a, b, c, min_v;
    int d[10][10];
    
    while(cin >> s, s)
    {
        v = 1, min_v = 0;        
        for(int i = 0; i < 10; ++i)
            for(int j = 0; j < 10; ++j)
                if(i == j)  d[i][j] = 0;
                else        d[i][j] = 100000000;
        
        for(int i = 0; i < s; ++i)
        {
            cin >> a >> b >> c;
            d[a][b] = d[b][a] = c;
            v = max(a + 1, max(b + 1, v));
        }
        
        for(int k = 0; k < v; ++k)
            for(int i = 0; i < v; ++i)
                for(int j = 0; j < v; ++j)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        
        for(int i = 0; i < v; ++i)
            for(int j = 1; j < v; ++j)
                d[i][0] += d[i][j];
        
        for(int i = 1; i < v; ++i)
            if(d[i][0] < d[min_v][0])
                min_v = i;
        
        cout << min_v << ' ' << d[min_v][0] << endl;
    }
}