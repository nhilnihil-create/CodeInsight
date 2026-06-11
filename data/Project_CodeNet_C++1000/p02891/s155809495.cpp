#include <iostream>
#include <iomanip>
#include <math.h>
#include <string>
#include <algorithm>
//#include <ctype.h>
#include <vector>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
using namespace std;

#define ll long long int
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repm(i, a, n) for (int i = a; i >= n; i--)
#define INF 1e9
#define LINF 1e17
#define MOD (int)(1e9 + 7)
#define pi 3.141592653589
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vs vector<string>
#define vii vector<vector<int>>
#define vll vector<ll>
#define vllll vector<vector<ll>>
#define vd vector<double>
#define ALL(a) (a).begin(), (a).end()
#define sort_v(a) sort(a.begin(), a.end())
#define reverse_v(a) reverse(a.begin(), a.end())
#define fi first
#define se second

void print(bool c)
{
    (c) ? (cout << "Yes" << endl) : (cout << "No" << endl);
}

void Print(bool c)
{
    (c) ? (cout << "YES" << endl) : (cout << "NO" << endl);
}

template <typename T>
T gcd(T a, T b)
{
    while (1)
    {
        if (a < b)
            swap(a, b);
        if (b == 0)
            break;
        a %= b;
    }
    return a;
}

template <typename T>
T lcm(T a, T b)
{
    return a * b / gcd(a, b);
}

bool cmp(const pii &a, const pii &b) //セカンドキー->ファーストキーの順ソート
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    /*string s;
    ll k;
    cin >> s >> k;

    ll cnt = 0, ans = 0;
    bool same = true;
    rep(i, 1, s.size())
    {
        if (s[i] != s[i - 1])
            same = false;
        if (s[i] == s[i - 1])
        {
            cnt++;
            i++;
        }
    }
    if (same)
        ans = s.size() * k / 2;*/
    string s;
    cin >> s;
    ll k, ans = 0;
    cin >> k;
    bool flag = true;
    char cc = s[0];
    rep(i, 0, s.size())
    {
        if (s[i] != cc)
            flag = false;
    }
    if (flag)
        ans = (s.size() * k) / 2;
    /*else
    {
        ll fr = 0, bk = 0;
        char c1 = s[0];
        rep(i, 0, s.size())
        {
            if (s[i] != c1)
            {
                break;
            }
            else
            {
                fr++;
            }
        }
        char c2 = s[s.size() - 1];
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] != c2)
            {
                break;
            }
            else
            {
                bk++;
            }
        }
        ll cnt = 0;
        char c3 = 'A';
        rep(i, 0, s.size())
        {
            //cout << cnt << endl;
            if (s[i] != c3)
            {
                c3 = s[i];
                ans += k * (cnt / 2);
                cnt = 1;
            }
            else
            {
                cnt++;
                if (i == s.size() - 1)
                    ans += k * (cnt / 2);
            }
        }
        //cout << res << endl;
        if (s[0] == s[s.size() - 1])
            ans -= (k - 1) * (fr / 2 + bk / 2 - (fr + bk) / 2);*/
    /*
        if (s[0] != s[s.size() - 1])
        {
            ans = k * cnt;
        }*/
    else
    {
        int a = 1, b = 1;
        rep(i, 1, s.size())
        {
            if (s[i] == s[i - 1])
                a++;
            else
                break;
        }
        repm(i, s.size() - 2, 0)
        {
            if (s[i] == s[i + 1])
                b++;
            else
                break;
        }

        ll cnt2 = 0;
        char c3 = 'A';
        rep(i, 0, s.size())
        {
            //cout << cnt << endl;
            if (s[i] != c3)
            {
                c3 = s[i];
                ans += k * (cnt2 / 2);
                cnt2 = 1;
            }
            else
            {
                cnt2++;
                if (i == s.size() - 1)
                    ans += k * (cnt2 / 2);
            }
        }
        //cout << res << endl;
        if (s[0] == s[s.size() - 1])
            ans -= (k - 1) * (a / 2 + b / 2 - (a + b) / 2);

        //ans = k * cnt - (a / 2 + b / 2 - (a + b) / 2) * (k - 1);
    }

    cout << ans << endl;
}