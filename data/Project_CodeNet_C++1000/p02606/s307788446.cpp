#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll l,r,d,count=0;
    cin>>l>>r>>d;
    for(int i=l;i<=r;i++)
    {
        if(i%d==0)
        {
            count++;
        }
    }
    cout<<count<<'\n';
    return 0;
}
