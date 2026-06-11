#include <bits/stdc++.h>
using namespace std;

int h[100010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    for(int i=n-1;i>=0;i--)cin>>h[i];

    bool ans=true;

    for(int i=1;i<n;i++)
    {
        if(h[i]-h[i-1]==1)h[i]--;
        else if(h[i]-h[i-1]>1)
        {
            ans=false;
            break;
        }
    }

    puts(ans?"Yes":"No");

    return 0;
}
