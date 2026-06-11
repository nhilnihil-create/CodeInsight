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

lli vis[N];
lli get(lli x) {

    if(x == vis[x])
        return x;
    return vis[x] = get(vis[x]);
}

void solve()
{

    lli n, m;
    cin>>n>>m;
    vector<pair<lli, lli> > v;
    for(int i = 0; i < n; i ++) {
        lli a, b;
        cin>>a>>b;
        if(a <= m) {
            v.push_back({b, a});
        }
    }
    for(int i = 1; i <= m; i ++) {
        vis[i] = i;
    }
    vis[m + 1] = m + 1;
    sort(v.rbegin(), v.rend());
    lli ans = 0, cnt = 0;
    for(int i = 0; i < (lli)v.size(); i ++) {
//        cout<<v[i].ss<<' ';
        lli X = get(v[i].ss);
  //      cout<<X<<endl;
        if(X <= m) {
            vis[X] = X + 1;
            ans += v[i].ff;
        }
    }
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
