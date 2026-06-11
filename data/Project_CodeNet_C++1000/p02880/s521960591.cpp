#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,flag=0;
    cin>>n;
    for(i=1; i<=9; i++)
    {
        if(n%i==0)
        {
            if((n/i)<=9)
            {
                flag=1;
                break;
            }
        }
    }
    if(flag)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
