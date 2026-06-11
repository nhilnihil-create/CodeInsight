#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long int t,n,q,i,b,c=0,d,k,p,v;
    cin>>n;
    long long int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";

    return 0;
}