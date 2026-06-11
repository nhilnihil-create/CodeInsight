#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;

long long n , m;
long long a[N] , b[N] ;

int main()
{
    cin>>n>>m;
    for(int i =0;i<n;i++)cin>>a[i];
    for(int i =0;i<n;i++)cin>>b[i];
    sort(a , a+n) ;
    sort(b , b+n , greater<long long>()) ;
    long long l = 0 , r= 1e17 ,ans = 0;
    while(l<=r)
    {
        long long mid = (l+r) /2;
        long long mm = 0;
        for(int i = 0;i<n;i++)
        {
            long long k = mid / b[i];
            mm+= max(0ll ,a [i] - k);
        }
        if(mm<=m)
        {
            r = mid-1;
            ans = mid;
        }
        else l = mid+1;
    }

    cout<<ans;
    return 0;
}
