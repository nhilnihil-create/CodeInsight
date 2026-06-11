#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(a) (a).size()
#define all(c) (c).begin(), (c).end()
#define rep(i, n) for (int i = 0; i < n; i++)
#define forn(i, n) for (int i = 1; i <= n; i++)
#define ford(i, n) for (int i = n; i >= 0; i--)
#define REP(i, a, n) for (int i = a; i < n; i++)
#define foreach(itr, c) for (__typeof((c).begin(), (c).end()) itr = c.begin(); itr != c.end(); itr++)
#define fill(a, b) memset(a, b, sizeof(a))
#define re return
#define INF 1e9
#define LINF 1e18
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<char> vs;
typedef vector<pi> vpi;

using namespace std;

int triangle(int N, vi L)
{
    int count = 0;

    if (N < 3)
    {
        return 0;
    }

    for (int i = 0; i < N - 2; i++)
    {
        for (int j = i + 1; j < N - 1; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                if ((L[i] != L[j] && L[i] != L[k]) && L[j] != L[k])
                {
                    if (L[i] + L[j] > L[k])
                    {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    int N;

    cin >> N;

    vi L(N);

    rep(i, N)
    {
        cin >> L[i];
    }

    sort(all(L));

    cout << triangle(N, L);
}