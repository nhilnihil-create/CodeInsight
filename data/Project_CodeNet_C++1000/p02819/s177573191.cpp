#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x;
    cin>>x;
    bool* seive = new bool [100010];
    for(int i=0;i<100010;i++)
        seive[i] = true;

    for(int i=2;i<1000;i++)
    {
        if( seive[i] )
        {
            for(int j=2*i;j<100010;j = j+i)
            {
                seive[j] = false;
            }
        }
    }
    for(int i=x;i<100010;i++)
    {
        if( seive[i] )
        {
            cout<<i;
            break;
        }
    }

}
