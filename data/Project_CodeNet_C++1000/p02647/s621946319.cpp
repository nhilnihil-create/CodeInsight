#define _USE_MATH_DEFINES
#define FAST ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#include <bits/stdc++.h>
#define Loop(x, l, r) for(int x = l; x < r; ++x)
#define LoopR(x, l, r) for(int x = r-1; x >= l; --x)
#define all(x) x.begin(), x.end()
#define Kill(x) return cout << x << '\n', 0
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
using namespace std;

const int N = 200'010;
int a[N];
int n, k;

int fen[N] = {};

void add(int r, int v)
{
    r++;
    while(r > 0)
    {
        fen[r] += v;
        r -= r & (-r);
    }
}
int get(int i)
{
    i++;
    int ans = 0;
    while(i <= n)
    {
        ans += fen[i];
        i += i & (-i);
    }
    return ans;
}

int main()
{
    FAST;
    cin >> n >> k; k = min(k, 43);
    Loop(i,0,n)
        cin >> a[i];
    Loop(_,0,k)
    {
        memset(fen,0,4*N);
        Loop(i,0,n)
        {
            int r = min(i+a[i], n-1);
            int l = max(i-a[i], 0);
            add(r, 1);
            add(l-1, -1);
        }
        Loop(i,0,n)
            a[i] = get(i);
    }
    Loop(i,0,n)
        cout << a[i] << ' ';
}
