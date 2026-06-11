#include <bits/stdc++.h>

using namespace std;
long long n;
int main()
{
    cin>>n;
    long long t = 100;
    for(long long i=1;i<=3760;i++)
    {
        t+=t/100;
        if(t>=n)
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
