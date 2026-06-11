#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
long long gcd(long long a,long long b)
{
    if(a%b==0) return b;
    long long c=a%b;
    return gcd(b,c);
}
int main() {
    long long a,b;
    cin>>a>>b;
    int ans=1;
    long long n;
    n=gcd(a,b);
    for(long long i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ans++;
            while(n%i==0) n/=i;
        }
    }
    if(n>1) ans++;
    printf("%d\n",ans);
}
