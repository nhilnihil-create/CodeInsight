#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long a,long long b)
{
    return b ? gcd(b, a % b) : a;
}
long long divide(long long x)
{
    long long cnt=0;
    for (long long i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            cnt++;
            while(x%i==0)   x/=i;
        }
    if(x>1) cnt++;
    return cnt;
}
int main()
{
    long long n,m;
    cin >> n >> m;
    long long u = gcd(n,m);
    cout << divide(u)+1 << endl;
    return 0;
}