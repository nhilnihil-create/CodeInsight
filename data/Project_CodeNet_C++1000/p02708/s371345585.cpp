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

int main() {
    long long ans=0;
    long long n,k;
    cin>>n>>k;
    for(long long i=k;i<=n+1;i++)
        ans=(ans+(n-i+1)*i+1)%1000000007;
    printf("%lld\n",ans);
    return 0;
}
