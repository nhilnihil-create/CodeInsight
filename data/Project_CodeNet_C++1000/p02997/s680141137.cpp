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

    lli n, k;
    cin>>n>>k;
    lli X = n - 2;
    if(k > (X * (X + 1)) / 2) {
        cout<<-1;
        return ;
    }
    vector<pair<lli, lli>>  ans;
    for(int i = 1; i < n; i ++) {
        ans.push_back({n, i});
    }
    lli cnt = (X * (X + 1)) / 2;
    for(int i = 1; i < n; i ++) {
        for(int j = i + 1; j < n; j ++) {
            if(cnt > k) {
                cnt --;
                ans.push_back({i, j});
            }
            else {
                break ;
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto it : ans)
        cout<<it.ff<<' '<<it.ss<<'\n';
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
