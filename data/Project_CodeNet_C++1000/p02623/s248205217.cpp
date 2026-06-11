#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t,m,n,k;
    t = 1;
    for(int i=0;i<t;i++)
    {
        cin>>n>>m>>k;
        int arr[n],brr[m];
        ll prea[n+1],preb[m+1];
        prea[0] = preb[0] = 0;
        for(ll j=0;j<n;j++)
        {
            cin>>arr[j];
            prea[j+1] = prea[j]+arr[j];
        } 
        for(ll j=0;j<m;j++)
        {
            cin>>brr[j];
            preb[j+1] = preb[j]+brr[j];
        }
        int maxi = 0;
        for(int i=0;i<=n;i++)
        {
            for(int j=m;j>=0;j--)
            {
                if(prea[i]+preb[j]<=k)
                {
                    maxi = max(maxi,i+j);
                    m = j;
                    break;
                }
            }
        }
        cout<<maxi;
    }
    return 0;
}