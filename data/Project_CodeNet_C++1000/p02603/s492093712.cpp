#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,a[1000],var;
    ll maxcost=1000;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]>a[i])
            {
                var=maxcost/a[i];
                maxcost=maxcost-(var*a[i])+(var*a[j]);
                i=j;
                i--;
                break;
            }
            else if(a[j]<a[i])
            {
                i=j;
                i--;
                break;
            }
        }
    }
    cout<<maxcost<<'\n';
    return 0;
}