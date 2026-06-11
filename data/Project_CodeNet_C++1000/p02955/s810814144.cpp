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

lli n, k;
lli a[N];

bool ok(lli X) {

    vector<lli> ps = {0};
    vector<lli> rem = {0};
    for(int i = 1; i <= n; i ++) {
        rem.push_back(a[i] % X);
    }
    sort(rem.begin(), rem.end());
    for(int i = 1; i <= n; i ++) {
        ps.push_back(ps.back() + (rem[i]));
    }

    for(int i = 1; i <= n; i ++) {
        lli choice1 = ps[i];
        lli choice2 = (n - i) * X - (ps[n] - ps[i]);
        if(max(choice1, choice2) <= k) {
            return 1;
        }
    }
    return 0;
}

void solve()
{

    cin>>n>>k;
    lli s = 0;
    for(int i = 1; i <= n; i ++) {
        cin>>a[i];
        s += a[i];
    }
    lli ans = 0;
    for(lli i = 1; i * i <= s; i ++) {
        if(s % i == 0) {
            if(ok(i)) {
                ans = max(ans, i);
            }
            if(ok(s / i)) {
                ans = max(ans, s / i);
            }
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
