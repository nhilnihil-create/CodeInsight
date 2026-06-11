#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>
#include <list>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <math.h>
#include <cmath>
#define rep(i,m,n) for(int i=m; i<(n); i++)
#define rrep(i,n,m) for(ll i=n;i>=m;i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int, int> pii;
ll inf=1LL<<60;
double eps=1e-14;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int mx = (n-1)*(n-2)/2;
    if(mx < k)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<pii> ans;
    rep(i,0,n-1)
    {
        ans.push_back(pii(i+1, n));
    }
    int add = mx - k;
    vector<pii> edge;
    rep(i,0,n-1)rep(j,0,i) edge.push_back(pii(i+1, j+1));
    rep(i,0,add) ans.push_back(edge[i]);
    cout << ans.size() << endl;
    rep(i,0,ans.size())
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
