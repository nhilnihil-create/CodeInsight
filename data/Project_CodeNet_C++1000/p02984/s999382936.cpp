#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
long long a[2000100];
long long ans[100010];
long long s[2000100];
int main()
{
    int n;
    cin >> n;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    for(int i=n+1;i<=2*n;i++)
    {
        a[i] = a[i-n];
    }
    int c=1;
    for(int i=1;i<=n/2;i++)
    {
        s[1] += a[1+c];
        s[2] += a[2+c];
        c +=2;
    }
    for(int i=3;i<=n;i+=2)
    {
        s[i] = s[i-2] - a[i-1] + a[i+2*(n/2-1)+1];
    }
    for(int i=4;i<=n;i+=2)
    {
        s[i] = s[i-2] - a[i-1] + a[i+2*(n/2-1)+1];
    }
    for(int i=1;i<=n;i++)
    {
        ans[i] = sum - 2*s[i];
        cout << ans[i] << " ";
    }
    return 0;
}