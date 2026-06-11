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

vector<lli> g[N];
lli ans ;
lli n, k;

void dfs(lli u, lli p) {

    lli avl = k - 1;
    if(p != -1) {
        avl --;
    }

    for(auto it : g[u]) {
        if(it == p) {
            continue ;
        }
        ans *= max(avl, 0LL);
        ans %= mod;
        avl --;
        dfs(it, u);
    }
    return ;
}

void solve()
{

    cin>>n>>k;
    for(int i = 0; i < n - 1; i ++ ) {
        lli a, b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    ans = k;

    dfs(1, -1);

    cout<<ans;

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
