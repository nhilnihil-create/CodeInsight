#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#pragma GCC optimize(2)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const double eps=1e-5;
const double pi=acos(-1.0);
const int MOD=1e9+7;
const int maxn=1e5+10;
ll k=1e9;
int main ()
{
    ll s=0;
    scanf("%lld",&s);
    ll x=0,y=0;
    x=s/k;
    if(s%k!=0)
        x++;
    y=x*k-s;
    printf("0 0 1 1000000000 %lld %lld",x,y);
    return 0;
}