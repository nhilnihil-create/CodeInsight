#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000000
#define ll long long int
ll a[2000100];
//ll number[20],used[20];
int main()
{
    ll n,i,count,sum=0;
    cin>> n >> count ;
    for(i=0;i<n;i++)
        cin >> a[i];
        sort(a,a+n);
    if(n<=count )
        cout << '0' << endl;
    else
    {
        n -=count;
        for(i=0;i<n;i++)
        sum+=a[i];
        cout << sum << endl;

    }
    return 0;
}
