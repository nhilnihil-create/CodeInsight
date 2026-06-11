#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5 , mod = 1e9 +7 , mx = 1e6 +5;


long long n , m , v , p ;
long long sol ;
long long a[N];
long long pre[N];

int main()
{
    cin>>n>>m>>v>>p;
    for(int i = 0 ; i< n  ; i++)
        cin>>a[i];
    sort(a , a + n);
    pre[0] = a[0];
    for(int i = 1;i<n;i++)
    {
        pre[i] = pre[i-1] + a[i];
    }
    v = n - v;
    for(long long i = 0;i<n;i++)
    {
        int l = i + 1 , r  = n-1;
        while(l<=r)
        {
            int mid = (l+r) /2;
            if(a[mid] - a[i] > m || pre[mid] - pre[i] - 1LL * a[i] * (mid - i) > 1LL*v * m)
            {
                r = mid - 1 ;
            }
            else
            {
                l = mid+1;
            }
        }
        if(n - r <= p)
            sol++;
    }
    cout<<sol;
    return 0;
}
