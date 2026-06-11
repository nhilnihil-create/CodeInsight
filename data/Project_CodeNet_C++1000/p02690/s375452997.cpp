#include<bits/stdc++.h>
using namespace std;
#define int long long
int power(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}
main()
{
    int x;
    cin>>x;
    for(int i=-1000; i<=1000; i++)
    {
        for(int j=-1000; j<=1000; j++)
        {
            int v=power(i,5)-power(j,5);

            if(v==x)
            {
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
}

