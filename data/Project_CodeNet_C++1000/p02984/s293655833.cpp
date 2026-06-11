#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <complex>
#include <map>
#include<unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include<bitset>
#include<deque>
#include<string>
#include<list>
#include<iterator>
#include<sstream>
#include <algorithm>
#include <numeric>
#include <math.h>

#define user spaesk
#define pi acos(-1)
#define lli long long int
#define ld long double
#define ff first
#define ss second
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

typedef vector<vector<lli> > matrix ;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const lli ths = 1LL << 40;
const int NN = 5e3 + 6;


void solve()
{

    lli n;
    cin>>n;
    lli a[n + 1];
    for(int i = 1; i <= n; i ++) {
        cin>>a[i];
    }

    lli X = 0;

    for(int i = n ; i > 1; i --) {
        if(i & 1) {
            X += a[i];
        }
        else {
            X -= a[i];
        }
    }

    lli x = a[1] - X;
    x /= 2;
//    cout<<x<<endl;

    lli ans[n + 1] = {};
    ans[1] = 2 * (a[1] - x);
    ans[2] = 2 * x;
    X = x;
    for(int i = 3; i <= n; i ++) {
        X = (a[i - 1] - X);
        ans[i] = 2 * X;
    }

    for(int i = 1; i <= n; i ++) {
        cout<<ans[i]<<' ';
    }

    cout<<"\n";
    return ;
}

/*
*/

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t = 1;
//    cin>>t;
    while(t --)
    {
        solve();
    }
    return 0;
}
