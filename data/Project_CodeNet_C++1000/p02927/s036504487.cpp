#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,d,f=0;
    cin>>m>>d;
    for(int j =1;j<=m;j++)
    {
        for(int i = 11;i<=d;i++)
        {
            int k10 = i%10;
            int k1 = i/10;
            if(k1>=2&&k10>=2)
            {
                
            
                if( k1*k10 == j)
                {
                    f++;
                }
            }
        }
    }
    
    cout<<f;
    return 0;
    
}