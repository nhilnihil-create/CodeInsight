#include<bits/stdc++.h>
using namespace std;
#define mx 1000000000000000000
#define ll long long int
//ll a[40001000];
//ll number[20],used[20];
int main()
{
    ll a[100000],n,i,count=0,k;
    cin>> n >> k;
    for(i=0;i<n;i++)
        cin>> a[i];
    sort(a,a+n);
    for(i=n-1;i>=0;i--)
    {
        if(a[i]>=k)
            count++;
        else
            break;
    }
    cout << count << endl;
    return 0;
}
