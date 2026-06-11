#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n ;
    cin>>n;
    int p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int m = INT_MAX;
    int ans =0;
    for(int i=0;i<n;i++)
    {
        m = min( m , p[i]);
        if( m == p[i] )
        {
            ans++;
        }
    }
    cout<<ans;
}