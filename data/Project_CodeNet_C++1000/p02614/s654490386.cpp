#include <bits/stdc++.h>
// bitwise operations need to be revised
using namespace std;
int main()
{

    int h,w,k,ans=0;
    cin>>h>>w>>k;
    char c[h][w];
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cin>>c[i][j];
        }
    }
    for(int maskR=0; maskR<(1<<h); maskR++)
    {
        for(int maskC=0; maskC<(1<<w); maskC++)
        {
            int black=0;
            for(int i=0; i<h; i++)
            {
                for(int j=0; j<w; j++)
                {
                    if(((maskR >> i) & 1) == 0&& ((maskC >> j) & 1) == 0&& c[i][j] == '#')
                        black++;
                }
            }
            if(black==k)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
