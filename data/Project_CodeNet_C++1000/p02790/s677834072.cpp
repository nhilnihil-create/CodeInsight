#include<bits/stdc++.h>

using namespace std;

int main()
{

    int x,y;
    cin>>x>>y;
    if(x==y)
    {
        while(x--)
        {
            cout<<y;
        }
    }
    else
    {
        int mi = min(x,y);
        int ma = max(x,y);
        while(ma--)
        {
            cout<<mi;
        }
    }
    
    
    return 0;
}