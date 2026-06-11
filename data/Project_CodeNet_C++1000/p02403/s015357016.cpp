#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h,w,i,j;
    while(1)
    {
        cin>>h>>w;
        if(h==0&&w==0)
            break;
        for(i=0;i<h;i++)
        {
            for(j=0;j<w;j++)
            {
                printf("#");
            }
            printf("\n");
        }
        printf("\n");
    }
}

