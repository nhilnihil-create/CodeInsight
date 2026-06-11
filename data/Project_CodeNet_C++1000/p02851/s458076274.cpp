/*input
10 7
14 15 92 65 35 89 79 32 38 46
*/
#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define debug cout << "hi" << endl

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MOD = 1e9 + 7;
const int INF32 = 1<<30;
const ll INF64 = 1LL<<60;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    ll ans = 0;
    vector<int> a(n);
    vector<int> pre(n + 1);
    map<int, ll> mapp;
    for(int i = 0; i < n; i++)
    {
    	cin >> a[i];
    	a[i]--;
    	if(!i) pre[i + 1] = (a[i] % k);
    	else pre[i + 1] = (pre[i] + (a[i] % k)) % k;
    }
    for(int i = 0; i < min(n + 1, k); i++)
    {
    	ans += mapp[pre[i]];
    	mapp[pre[i]]++;
    }
    for(int i = k; i < n + 1; i++)
    {
    	mapp[pre[i - k]]--;
    	ans += mapp[pre[i]];
    	mapp[pre[i]]++;
    }
    cout << ans;

    return 0;
}