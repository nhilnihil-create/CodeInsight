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

//最小公倍数
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

//最大公約数
template <typename T>
T lcm(T a, T b)
{
    return a * b / gcd(a, b);
}
//セカンドキー->ファーストキーの順ソート
bool cmp(const pii &a, const pii &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, a, b, c, d;
string s;
bool f = true;

int move(char chr)
{
    if (chr == 'A')
    {
        if (s[a + 1] == '.' && a + 1 != b)
        {
            a++;
            return 1;
        }
        else if (s[a + 2] == '.' && a + 2 != b)
        {
            a += 2;
            return 1;
        }
    }
    else
    {
        if (s[b + 1] == '.' && b + 1 != a)
        {
            b++;
            return 1;
        }
        else if (s[b + 2] == '.' && a + 2 != a)
        {
            b += 2;
            return 1;
        }
    }
    f = false;
    return 0;
}

void Move(int x)
{
    if (x == 0)
    {
        while (a < c)
        {
            if (!move('A'))
                break;
        }
    }
    else
    {
        while (b < d)
        {
            if (!move('B'))
                break;
        }
    }
}

int main(void)
{
    cin >> n >> a >> b >> c >> d;
    a--, b--, c--, d--;
    cin >> s;

    if (c > d)
    {
        while (1)
        {
            if (s[b - 1] == '.' && s[b + 1] == '.')
                break;
            if (b == d)
            {
                f = false;
                break;
            }
            if (!move('B'))
                break;
        }
    }
    Move(c < d);
    Move(c > d);
    print(f);
}