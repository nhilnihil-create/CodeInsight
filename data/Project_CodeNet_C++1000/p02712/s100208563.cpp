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
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) if(i%3&&i%5) ans+=i;
    printf("%lld\n",ans);
    return 0;
}
