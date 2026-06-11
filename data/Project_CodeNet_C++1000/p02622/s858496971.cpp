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
const int maxn=1e6+50;
const int inf=0x3f3f3f3f;
const int MOD=1e9+7;
const int HASH=131;

int main()
{
    string s,ss;
    cin>>s>>ss;
    int len=s.size();
    int ans=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]!=ss[i]) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
