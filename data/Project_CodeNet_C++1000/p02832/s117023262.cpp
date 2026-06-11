#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,c=0,nxt=1,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(x==nxt)
        {
            ++nxt;
            ++c;
        }
    }
    if(c!=0)
    cout<<n-c;
    else
        cout<<-1;
    return 0;
}
