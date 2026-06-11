#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define ll long long
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define vali 1000000000000000000
using namespace std;
int main()
{
    ll n;
    l sum=0.0;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    sum=(l)((a[0]+a[1])/2.0);
    //cout<<sum<<endl;
    for(int i=2;i<=n-1;i+=1)
    {
        sum=(l)((sum+a[i])/2.0);
    }
    cout<<fixed<<setprecision(7)<<(l)sum<<endl;
}