#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed  main()
{
    int i, j, x, a, b, sz;
    cin>>x;
    sz=sqrt(x);
    for(i=-sz; i<=sz; i++)
    {
        for(j=-sz; j<=sz; j++)
        {
            a=i*i*i*i*i;
            b=j*j*j*j*j;
            if((a-b)==x)
            {
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
}
