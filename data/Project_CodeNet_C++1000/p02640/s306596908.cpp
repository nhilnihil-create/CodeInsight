#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,i,p=0;
    cin>>x>>y;
    for(i=0;i<=100;i++)
    {
        p=x-i;
        if(p>=0)
        {
            if((i*2+p*4)==y)
            {
                cout<<"Yes"<<endl;
            return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}



