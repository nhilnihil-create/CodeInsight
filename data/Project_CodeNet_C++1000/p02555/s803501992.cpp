#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
// #include <cmath>
// #include <map>
// #include <set>
// #include <deque>
// #include <stack>
// #include <vector>
using namespace std;
#define debug freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
// #define PI acos(-1)
typedef long long ll;
const ll mod=1e9+7;

int d[200000];
int main()
{
	//debug;
	ios;
	ll n;
	cin>>n;
    d[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i-3;j++)
        {
            d[i]+=d[j];
            d[i]%=mod;
        }
    }
    cout<<d[n];
    return 0;
}
