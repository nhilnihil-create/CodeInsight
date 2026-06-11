#include <bits/stdc++.h>
#define rep0(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i <= (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<string, int, int> TU;
typedef tuple<int, int, int> TI;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll input[n+1];
    rep1(i, n)
    {
        ll tmp;
        cin >> tmp;
        input[i] = tmp;
    }
    int memo[n+1]={}, index = 1;
    ll now = 1, loop = 0;
    while (m > 0)
    {
        if (memo[now] != 0)
        {
            loop = index - memo[now];
            break;
        }
        memo[now] = index;
        now = input[now];
        m--;
        index++;
    }
    if (!loop)
    {
        cout << now << endl;
    }
    else
    {
        ll mod = m % loop;
        rep0(i, mod)
        {
            memo[now] = index;
            now = input[now];
            m--;
            index++;
        }
        cout << now << endl;
    }
}
