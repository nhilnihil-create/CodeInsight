#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#define PI			2*acos(0.0)
int main()
{
    int n,i;
    cin >>n;
    int a[n+1],c=0,y1,y2=0;
    for(i=1;i<=n;i++)
    {
        cin >>a[i];
        if(a[i]!=i)
        {
            if(c==0)
            {
                c++;
                y1=i;
            }
            else if(c==1)
            {
                c++;
                if(a[i]==y1)
                {
                    y2=1;
                }
            }
            
        }
    }
    if(c==2&&y2==1)
    {
        cout <<"YES";
    }
    else if(c==0)
    {
        cout <<"YES";
    }
    else
        cout <<"NO";
    return 0;
}