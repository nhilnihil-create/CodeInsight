#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#define mem(a,b) memset(a,b,sizeof (a))
#define endl '\n'
#define pb push_back
typedef long long ll;
const int maxn=200010;
const int inf=1e9;
const ll mod=998244353;
const double pi=3.14159265358979;
const double ep=0.0;
using namespace std;
ll dp[1110000][2];
int main()
{
    string s;
    cin>>s;
    s='0'+s;
    vector<int>vec;
    for (int i=0;i<s.size();i++)
        vec.pb(s[i]-'0');
    for (int i=0;i<=s.size();i++)
        for (int j=0;j<2;j++)
            dp[i][j]=1e18;
    dp[0][0]=0;
    for (int i=0;i<s.size();i++)
    {
        dp[i+1][0]=min(dp[i+1][0],dp[i][0]+vec[i]);
        dp[i+1][1]=min(dp[i+1][1],dp[i][0]+vec[i]+1);
        dp[i+1][0]=min(dp[i+1][0],dp[i][1]+10-vec[i]);
        dp[i+1][1]=min(dp[i+1][1],dp[i][1]+10-vec[i]-1);
    }
    ll ans=dp[s.size()][0];
    cout<<ans<<endl;
    return 0;
}
