#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x=1;
    int ans =0;
    for(int i=0;i<n;i++)
    {
        if( a[i] == x)
        {
            x++;
        }
        else ans++;
    }
    if( ans == n)
        cout<<-1;
    else cout <<ans;
}