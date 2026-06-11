#include<iostream>
#include<cmath>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    if(k>n)
    {
        if(k-n<n)
            cout<<k-n;
        else
            cout<<n;
        return 0;
    }

    if(n>=k)
        n=n%k;
    if(k>n)
    {
        if(k-n<n)
            cout<<k-n;
        else
            cout<<n;
    }
}
