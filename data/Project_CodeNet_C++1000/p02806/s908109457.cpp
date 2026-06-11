#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define endl "\n"
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
using namespace std;

const int N = 7777;
int n, k, s;
int inf = 1e9;
map <string, int> mp;
int pref[N];
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("flow2.in", "r", stdin);
    //freopen("flow2.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        string s;
        int k;
        cin >> s >> k;
        mp[s] = i;
        pref[i] = pref[i - 1] + k;
    }
    string s;
    cin >> s;
    int k = mp[s];
    cout << pref[n] - pref[k] << endl;
    return 0;
}
