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
typedef long long ll;
const int maxn=3e5+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

int main()
{
    int k;
    cin>>k;
    int ans=1;
    for(int i=7;i%k;i=(i*10+7)%k)
    {
        if(++ans>k) {ans=-1;break;}
    }
    cout<<ans;
}
