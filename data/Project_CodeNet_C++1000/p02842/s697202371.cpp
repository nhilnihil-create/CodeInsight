#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    for(int i=n;i>=0;i--)
    {
        int x=i*1.08;
        if(x==n)
        {
            cout<<i<<"\n";
            break;
        }
        else if(x<n)
        {
            cout<<":(\n";
            break;
        }
    }

    return 0;
}
