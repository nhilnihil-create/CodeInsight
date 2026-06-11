#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    vector<double> a(n);

    for(int i=0;i<n;i++)cin>>a[i];

    sort(a.begin(),a.end());

    double ans=0;

    for(int i=1;i<n;i++)
    {
        a[i]=(a[i-1]+a[i])/2.0;
        ans=a[i];
    }

    printf("%.5lf", ans);

    return 0;
}
