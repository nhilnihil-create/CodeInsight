#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,n;
    cin>>a>>b>>n;

    int r=max(a,b);
    int x=1;
    while(r<n)
    {
        x++;
        r+=max(a,b);
    }
    cout<<x;
    return 0;
}
