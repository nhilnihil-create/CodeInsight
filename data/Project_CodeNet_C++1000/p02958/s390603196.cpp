#include<iostream>
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;
int main()
{
    fastio;
    long long n,i;
    cin>>n;
    long long a[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]!=i)
        {
            swap(a[i],a[a[i]]);
            break;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]!=i)
        {
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}