#include <bits/stdc++.h>
#define lli long long int
#define all(c) c.begin(), c.end()
#define mp(x, y) make_pair(x, y)
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define deb(x) cout << #x << " " << x << endl;
#define rep(i, n) for (i = 0; i < n; i++)
#define Rep(i, k, n) for (i = k; i < n; i++)
#define write(x) cout << x << " ";
#define writeLine(x) cout << x << endl;
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define ppi pair<int, int>
using namespace std;

int main()
{
    fast;

#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<char> a(n);
    bool allRed = true;
    int countRed = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 'W')
        {
            allRed = false;
        }
        else
        {
            countRed++;
        }
    }
    if (allRed)
    {
        cout << 0 << endl;
        return 0;
    }
    int moves = 0;
    for (int i = 0; i < countRed; i++)
    {
        if (a[i] != 'R')
        {
            moves++;
        }
    }
    cout << moves << endl;
}
