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
#define int long long int
#define ld long double
#define ff first
#define ss second
#define lower(a) transform(a.begin(),a.end(),a.begin(),::tolower);

using namespace std;

typedef vector<vector<int> > matrix ;

const int N = 3e5 + 500;
const long long mod = 1e9 + 7;
const long long cmod = 998244353 ;
const long long inf = 1LL << 61;
const int M = 1e6 + 500;
const int ths = 1LL << 40;
const int NN = 5e3 + 6;

const int maxN = 1000007;

///abc 160_e
///easy probably

void solve()
{

    int x, y, a, b, c;
    cin>>x>>y>>a>>b>>c;
    int p[a], q[b], r[c];
    for(int i = 0; i < a; i ++) {
        cin>>p[i];
    }
    for(int i = 0; i < b; i ++) {
        cin>>q[i];
    }
    for(int i = 0; i < c; i ++) {
        cin>>r[i];
    }
    sort(p, p + a);
    reverse(p, p + a);
    sort(q, q + b);
    reverse(q, q + b);
    sort(r, r + c);
    reverse(r, r + c);
    vector<int> XX;

    int ans = 0;
    for(int i = 0; i < x; i ++) {
        XX.push_back(p[i]);
        ans += p[i];
    }

    for(int i = 0; i < y; i ++) {
        XX.push_back(q[i]);
        ans += q[i];
    }

    sort(XX.begin(), XX.end());
    for(int i = 0; i < min(c, (int)XX.size()); i ++) {
        if(r[i] > XX[i] ) {
            ans += r[i] - XX[i];
        }
    }

    cout<<ans;

    cout<<"\n";
    return ;
}

/*
*/

int32_t main()
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
