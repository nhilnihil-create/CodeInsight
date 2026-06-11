#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,ans;
    cin>>a>>b;
    for(int i=1;i<=1010;i++)
    {
        if(a == i*8/100 && b == i*10/100)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}


