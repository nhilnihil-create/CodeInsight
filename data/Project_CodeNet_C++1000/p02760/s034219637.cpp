/*
    Author: Aryan Yadav
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define f(i, a, b) for (long long i = a; i < b; i++)
#define rep(i, a, b) for (long long i = a; i <= b; i++)
#define fm(i, a, b) for (long long i = a; i > b; i--)
#define repm(i, a, b) for (long long i = a; i >= b; i--)
#define vi vector<int>
#define vl vector<long long>
#define vs vector<string>
#define pqmaxi priority_queue<int>
#define pqmaxl priority_queue<ll>
#define pqmini priority_queue<int, vi, greater<int>>
#define pqminl priority_queue<ll, vl, greater<ll>>
#define all(x) x.begin(), x.end()
#define test     \
    ll test;     \
    cin >> test; \
    while (test--)
#define pb(i) push_back(i)
#define mp(i, j) make_pair(i, j)
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(NULL)

int main()
{
    fast;
    ll n;
    ll a[3][3];
    bool tick[3][3];

    f(i, 0, 3)
    {
        f(j, 0, 3)
        {
            cin >> a[i][j];
            tick[i][j] = false;
        }
    }
    cin >> n;
    vl b(n);
    f(i, 0, n)
    {
        cin >> b[i];
    }
    f(i, 0, n)
    {
        f(a1, 0, 3)
        {
            f(b1, 0, 3)
            {
                if (b[i] == a[a1][b1])
                    tick[a1][b1] = true;
            }
        }
    }

    ll k = 0;
    f(i, 0, 3)
    {
        if (tick[i][0] && tick[i][1] && tick[i][2])
            k = 1;
    }
    f(i, 0, 3)
    {
        if (tick[0][i] && tick[1][i] && tick[2][i])
            k = 1;
    }
    if (tick[0][0] && tick[1][1] && tick[2][2])
        k = 1;
    if (tick[0][2] && tick[1][1] && tick[2][0])
        k = 1;

    if (k == 0)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
}