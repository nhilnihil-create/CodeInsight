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
long long x,k,d;

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    scanf("%lld%lld%lld",&x,&k,&d);
    x = abs(x);
    long long t1 = x/d;
    //long long t2 = k - t1;
    if(t1<=k){//先移动t1次
        x -= t1 * d;
        k -= t1;
    }
    else if(t1>k){ //不够t1移动k次
        x -= k * d;
        k = 0;
    }
    if(k==0)
        printf("%lld\n",abs(x));
    else{
        k = k % 2;
        x -= k * d;
        printf("%lld\n",abs(x));
    }

    return 0;
}
