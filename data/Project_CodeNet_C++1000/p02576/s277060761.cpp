#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <functional>
#include <vector>
#include <stack>
#include <set>
using namespace std;
typedef unsigned long long ll;
const int maxn=2e5+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;



int main()
{
    int  n,x,t;
    cin>>n>>x>>t;
    int num;
    if(n%x==0)
        {
            num=n/x;
        }
    else num=n/x+1;
    printf("%d\n",num*t);
    return 0;
}
