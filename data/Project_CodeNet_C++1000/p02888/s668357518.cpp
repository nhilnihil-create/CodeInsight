#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
int a[2010];
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int cnt=0;
    for(int i=1;i<=n-2;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                if(a[i]+a[j]<=a[k]) break;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}