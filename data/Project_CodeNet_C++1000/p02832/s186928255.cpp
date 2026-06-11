#include <iostream>
#include <cstring>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;


#include <bits/stdc++.h>
using namespace std;

const int N=222222;
int a[N],b[N];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(b,-1,sizeof(b));

    b[0]=0;
    int ans=-1;
    for (int i=1;i<=n;i++) {
        int x=a[i];
        if (b[x-1]==-1) continue;
        b[x]=max(b[x], b[x-1]+1);
        ans=max(ans, b[x]);
    }
    if (ans>0) ans=n-ans;
    else ans=-1;
    printf("%d\n", ans);
    return 0;
}
