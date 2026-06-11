#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,j;
    cin>>a>>b;
    if(a<b)
    {
        for(i=1;i<=b;i++)
        {
            cout<<a;
        }
        cout<<endl;
    }
    else
    {
        for(i=1;i<=a;i++)
        {
            cout<<b;
        }
        cout<<endl;
    }
}
