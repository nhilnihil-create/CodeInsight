#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int a,b,k=0;
    cin>>a>>b;

    while(llabs(a-k)!=llabs(b-(k+1)))
    {
        if(llabs(a-k)==llabs(b-k))
        {
            break;
        }
        else
            k++;
    }

    if(llabs(a-k)==llabs(b-k))
    {
        cout<<k<<endl;
    }
    else
        cout<<"IMPOSSIBLE"<<endl;

    return 0;
}
