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
int cnt[200005];
int main() {
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        cnt[t]++;
    }
    for(int i=1;i<=n;i++) printf("%d\n",cnt[i]);
    return 0;
}
