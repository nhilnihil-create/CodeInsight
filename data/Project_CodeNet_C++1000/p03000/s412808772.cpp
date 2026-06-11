#include <bits/stdc++.h>
#define cf ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    cf;
    int i, n, k ;
    cin >> n >> k  ;
    int a[n],d[n+1];
    d[0]=0;
    int x=1;
    for(i=0; i<n; i++)
    {
        cin >> a[i];
        d[i+1]=a[i]+d[i];
        if(d[i+1]<=k)
            x++;
    }
    cout << x;
    return 0;
}