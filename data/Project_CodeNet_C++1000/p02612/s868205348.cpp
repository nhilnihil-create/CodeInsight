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
typedef  long long ll;
const int maxn=1e6+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;


int main()
{
    int n;
    cin>>n;
    int i=0;
    while(i*1000<n)
    {
        i++;
    }
    printf("%d\n",i*1000-n);
    return 0;
}
