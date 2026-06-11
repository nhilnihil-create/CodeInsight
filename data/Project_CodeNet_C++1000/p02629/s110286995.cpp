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
#include <bitset>
using namespace std;
typedef  long long ll;
const int maxn=2e5+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

int a[maxn];
int main()
{
    ll n;
    cin>>n;
    string s;
    while(n--)
    {
        s=(char)('a'+n%26)+s;
        n/=26;
    }
    cout<<s<<endl;
}
