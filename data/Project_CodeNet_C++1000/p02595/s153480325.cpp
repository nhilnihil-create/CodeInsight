#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,d;
    cin>>n>>d;
    double a[n],b[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i]>>b[i];
    }
    int cnt=0;
    for (int i = 0; i < n; ++i)
    {
        long double x=sqrt((a[i]*a[i])+(b[i]*b[i]));
        if (x<=d)
        {
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
}