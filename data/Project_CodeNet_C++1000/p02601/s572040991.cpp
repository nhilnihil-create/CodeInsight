#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string.h>
#include <iomanip>
using namespace std;
#define int long long
#define ull unsigned long long
#define F first
#define S second
#define nl "\n"
#define ld long double
#define div 1000000007
#define pi 3.14159265358979323846
#define pb push_back
bool ans=0;
void f(int a,int b,int c,int k)
{
    if(a<b && b<c)
    {
        ans=1;
        return;
    }
    if(k==0)
    {
        return;
    }
    f(2*a,b,c,k-1);
    f(a,2*b,c,k-1);
    f(a,b,2*c,k-1);
}
void solve()
{
    int a,b,c,k;cin>>a>>b>>c>>k;
    f(a,b,c,k);
    if(ans)
        cout<<"Yes"<<nl;
    else
        cout<<"No"<<nl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
