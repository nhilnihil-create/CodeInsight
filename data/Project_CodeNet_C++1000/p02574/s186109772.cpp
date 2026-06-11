#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
int spf[1000001];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i <= 1000000; i++)
        spf[i] = i;
    for (int i = 2; i <= 1000000; i += 2)
    {
        spf[i] = 2;
    }
    for (int i = 3; i * i <= 1000000; i += 2)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                spf[j] = i;
            }
        }
    }
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        while (a[i] != 1)
        {
            cnt[spf[a[i]]]++;
            int div=spf[a[i]];
            while (a[i] % div == 0)
                a[i] /= div;
        }
    }
    bool yes = true, no = false;
    for (auto x : cnt)
    {
        if (x.second != 1)
        {
            yes = false;
        }
        if (x.second == n)
        {
            no = true;
        }
    }
    if (yes)
        cout << "pairwise coprime";
    else if (no)
        cout << "not coprime";
    else
        cout << "setwise coprime";
    return 0;
}