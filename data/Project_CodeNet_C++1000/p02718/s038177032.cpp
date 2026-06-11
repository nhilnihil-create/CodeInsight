#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n, i, cnt = 0, sum = 0;
    float x;
    cin>>n>>m;
    int a[n];
    for(i = 0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i = 0; i<n; i++)
    {
        sum += a[i];
    }
    x = (1.0/(4.0*m))*sum;

    for(i = 0; i<n; i++)
    {
        if(a[i]>=x)
        {
            cnt++;
        }
    }
    if(cnt>=m) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
