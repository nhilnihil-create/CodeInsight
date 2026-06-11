#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int sum =0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    sum /= n;
    int sum1 = sum+1;
    int ans =0;
    int ans2 = 0;
    for(int i=0;i<n;i++)
    {
        ans += ( sum - a[i] )*( sum - a[i] );
        ans2 += ( sum1 -a[i])*( sum1 -a[i] );
    }
    cout<<min( ans , ans2);
}