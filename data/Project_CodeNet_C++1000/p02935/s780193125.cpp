//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,x,i,j;
    double cur;
    cin>>n;
    ll a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    cur=a[0];
    for(i=1; i<n; i++)
    {
        cur=cur+a[i];
        cur/=(2*1.0);
    }
    cout.setf(ios::fixed);
    cout.precision(7);
    cout<<cur<<endl;
    return 0;
}



