#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    int h[n];
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    int curr = 0;
    int ans = 0;
    for(int i=0;i<n-1;i++)
    {
        if( h[i] >= h[i+1])
        {
            curr++;
            ans = max( ans , curr);
        }
        else curr =0;
    }
    cout<<ans;
}