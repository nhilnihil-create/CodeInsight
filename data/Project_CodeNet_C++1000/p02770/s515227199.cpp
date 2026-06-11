#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k, q;
    cin>>k>>q;
    vector<long long> d(k);
    for (long long &x: d)
        cin>>x;

    for (int qi=0; qi<q; qi++)
    {
        long long n, x, m;
        cin>>n>>x>>m;

        long long t = 0;
        for (int i=0; i<k; i++)
            t += (d[i]+m-1)%m+1;
        long long s = x+(n-1)/k*t;
        for (int i=(n-1)/k*k; i<n-1; i++)
            s += (d[i%k]+m-1)%m+1;
        cout<<n-1-(s/m-x/m)<<endl;
    }
}
