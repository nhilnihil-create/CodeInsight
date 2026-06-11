#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef vector<int> vi;
const int INF = 1LL << 60; //10e18+10e17ちょっとくらい
const int MOD = 1000000007;
const int MAX_N = 200100;

signed main()
{
    //  以降 cin の入力元が 'input.txt' になる
    //std::ifstream in("input.txt");
    //std::cin.rdbuf(in.rdbuf());
    int n, k, c;
    cin >> n >> k >> c;
    vi v;
    rep(i, n)
    {
        char tmp;
        cin >> tmp;
        if (tmp == 'o')
            v.emplace_back(i);
    }

    if (c == 0 && v.size() > k)
        return 0;

    vi ans;
    map<int, int> mp;
    int bef = -INF;
    int cnt = 0;
    rep(i, v.size())
    {
        int tmp = v[i];
        if (tmp - bef > c)
        {
            mp[tmp] = 0;
            bef = tmp;
            cnt++;
        }
        if (cnt == k)
            break;
    }

    bef = INF;
    cnt = 0;
    rep(i, v.size())
    {
        int tmp = v[v.size() - 1 - i];
        if (bef - tmp > c)
        {
            if (mp.count(tmp))
                ans.emplace_back(tmp);
            bef = tmp;
            cnt++;
        }
        if (cnt == k)
            break;
    }

    sort(all(ans));
    rep(i, ans.size())
    {
        cout << ans[i] + 1 << endl;
    }

    return 0;
}