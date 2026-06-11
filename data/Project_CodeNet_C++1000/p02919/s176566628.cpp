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
    vector<pair<lli, lli> > v;
    for(int i = 1; i <= n; i ++) {
        cin>>a[i];
        v.push_back({a[i], i });
    }

    multiset<lli> s({0, 0, n + 1, n + 1});

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    lli ans = 0;
    for(int i = 0; i < n; i ++) {
        lli num = v[i].ff;
        lli id = v[i].ss;
        auto it = s.lower_bound(id);
        lli R1 = *it;
        it ++;
        lli R2 = *it;
        it --;
        it --;
        lli L1 = *it;
        it --;
        lli L2 = *it;
        if(R1 < R2) {
            ans += num * (R2 - R1) * (id - L1);
        }
        if(L2 < L1) {
            ans += num * (L1 - L2) * (R1 - id);
        }
        s.insert(id);
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
