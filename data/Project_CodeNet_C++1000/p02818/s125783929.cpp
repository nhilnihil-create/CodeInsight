#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
#include<cmath>
#include<bitset>
#include<cassert>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<fstream>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
int main()
{
    fast_io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    ll a, b, n;
    cin >> a >> b >> n;

    if (a > n)
        cout << a - n << " " << b << endl;
    else
    {
        ll taka = 0, auki = 0;
        if (b > 0)
        {
            ll rem = n - a;
            if (b >= rem) auki = b - rem;
        }

        cout << taka << " " << auki << endl;
    }

    return 0;
}