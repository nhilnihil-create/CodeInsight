#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
map<char, vector<int>> mp;
int main()
{
    string s,t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    vector<vector<int> > is(26);
    rep(i,n)
    {
        is[s[i] - 'a'].push_back(i+1);
    }
    rep(i, n)
    {
        is[s[i] - 'a'].push_back(i+n+1);
    }
    ll ans = 0;
    int p = 0;
    rep(i,m)
    {
        int c = t[i]-'a';
        if(sz(is[c]) == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        p = *upper_bound(is[c].begin(), is[c].end(), p);
        if (p>=n)
        {
            p -= n;
            ans+= n;
        }
    }
    ans += p;
    cout << ans << endl;
}