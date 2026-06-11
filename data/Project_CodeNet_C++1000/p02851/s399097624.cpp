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
#include <tuple>
#include <cassert>
#include <array>
#include <iomanip>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ti = tuple<int, int, int>;

#define pb push_back
#define mp make_pair
#define debug(x) cerr << #x << ": " << x << endl
// #define int long long 

const double eps=1e-14;
const int mod = 1e9 + 7;
const int inf = ((1<<30)-1);
const ll linf = (1LL<<60);
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) a[i]--;
    vector<int> s(n+1);
    for(int i=0; i<n; i++) s[i+1] = (s[i]+a[i])%k;
    map<int,int> mp;
    ll ans = 0;
    queue<int> q;
    for(int j=0; j<n+1; j++)
    {
        ans += mp[s[j]];
        mp[s[j]]++;
        q.push(s[j]);
        if(q.size() == k)
        {
            mp[q.front()]--;
            q.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
