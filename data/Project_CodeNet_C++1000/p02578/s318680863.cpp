
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<time.h>
#include<vector>
using namespace std;
long long ans;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n,a[200005];
    scanf("%d",&n);
    for(int i=0; i<n; ++i)
        scanf("%d",&a[i]);

    for(int i=0; i<n-1; i++){
        if(a[i]>a[i+1]){
            ans += a[i]-a[i+1];
            a[i+1] = a[i];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
