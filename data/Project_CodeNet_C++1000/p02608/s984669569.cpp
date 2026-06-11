#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int main()
{
    int N;
    cin>>N;
    int x,temp;
    int count[N]={0,};
    for(int n=1;n<=N;++n)
    {x=ceil(sqrt((float)n));
        for(int i=1;i<x;++i)
       {
        for(int j=1;j<x;++j)
        {
            for(int k=1;k<x;++k)
            {
                temp=(i*i+j*j+k*k+i*j+i*k+j*k);
                if(temp==n)
                    ++count[n-1];
                else if(temp>n)
                    break;
            }
        }
       }
       cout<<count[n-1]<<"\n";
    }

    return 0;
}

