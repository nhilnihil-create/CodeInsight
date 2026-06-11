#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T &a, T b)
{
    if(a < b)
    {
        a = b;
        return true;
    }
    return false;
}

struct ABCD{
    int a, b, c, d;
    ABCD(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
    ABCD()
    {
        a = 0;
        b = 0;
        c = 0;
        d = 0;
    }
};

void dfs(vector<vector<int>> &all, int n, int m, vector<int> v)
{
    if(v.empty())
    {
        for(int i=1; i<=m; i++)
        {
            v.push_back(i);
            dfs(all, n, m, v);
            v.pop_back();
        }
    }
    else if(v.size() == n)
    {
        all.push_back(v);
    }
    else
    {
        int bn = v.back();
        for(int i=bn; i<=m; i++)
        {
            v.push_back(i);
            dfs(all, n, m, v);
            v.pop_back();
        }
    }
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<ABCD> kumis;
    for(int i=0; i<q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        kumis.emplace_back(a-1, b-1, c, d);
    }

    vector<vector<int>> all;
    dfs(all, n, m, vector<int>());

    int ans = 0;
    for(auto &vec : all)
    {
        int sun = 0;
        for(auto kumi : kumis)
        {
            if(vec.at(kumi.b) - vec.at(kumi.a) == kumi.c) sun += kumi.d;
        }
        chmax(ans, sun);
    }
    cout << ans << endl;

    return 0;
}
