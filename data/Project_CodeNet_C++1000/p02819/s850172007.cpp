#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool flag=true;
    cin>>n;
    --n;
    while(flag)
    {
        flag=false;
        ++n;
        for(int i=2;i*i<=n;i++)
        {
            if((n%i)==0)
                {
                    flag=true;
                    break;
                }
        }
    }
    cout<<n;
    return 0;
}

