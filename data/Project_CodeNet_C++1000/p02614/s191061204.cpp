/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h,w,k;
    cin>>h>>w>>k;
    char c[h][w];
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            cin>>c[i][j];
        }
    }

    int ans=0;
    for(int i=0;i<(1<<h);i++){
        for(int j=0;j<(1<<w);j++){
            int black=0;

            for(int p=0;p<h;p++){
                for(int q=0;q<w;q++){
                    if(((i>>p)&1)==0&&((j>>q)&1)==0&&c[p][q]=='#') black++;
                }
            }
            if(black==k) ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
