#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long n;
    cin >> n;
    long long a[n+1]={},b[n+1]={};
    long long sum=0;

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        sum^=a[i];
    }
    for(int i=0;i<n;i++)
    {
        b[i]^=sum;
        b[i]^=a[i];
        cout << b[i] << " ";
    }

    return 0;
}
