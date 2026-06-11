#include <bits/stdc++.h>
using namespace std;

int main()
{
    // freopen("input01.txt", "r", stdin);
    // freopen("output01.txt", "w", stdout);
    int n,r=0,ans=0,i;
    cin >> n;
    char arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 'R')
            r++;
    }
    for(i=0;i<r;i++)
    {
        if(arr[i]=='W')
            ans++;
    }
    cout<<ans;
    return 0;
}