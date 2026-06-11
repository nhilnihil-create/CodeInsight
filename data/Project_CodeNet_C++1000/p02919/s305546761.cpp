#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100100;

int a[N];
int Next1[N];
int Next2[N];
int Last1[N];
int Last2[N];
vector <int> iNext[N];
vector <int> iLast[N];

int main()
{
    int n;  cin >> n;

    for(int i = 1; i <= n; i++) scanf("%d", a + i);

    a[0] = a[n + 1] = n + 1;

    vector <int> stk;

    /// Last1
    stk.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        while(!stk.empty() && a[stk.back()] < a[i])
            stk.pop_back();
        Last1[i] = stk.back();
        iLast[stk.back()].push_back(i);
        stk.push_back(i);
    }
    stk.clear();

    /// Last2
    for(int j : iLast[0])   Last2[j] = 0;

    stk.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        for(int j : iLast[i])
        {
            int I = 0;

            for(int k = 20; ~k; --k)
                if(I + (1 << k) <= stk.size() && a[stk.end()[-(I + (1 << k))]] < a[j])
                    I += (1 << k);

            Last2[j] = stk.end()[- ++I];
        }

        while(!stk.empty() && a[stk.back()] < a[i])
            stk.pop_back();
        stk.push_back(i);
    }
    stk.clear();

    /// Next1
    stk.push_back(n + 1);
    for(int i = n; i >= 1; i--)
    {
        while(!stk.empty() && a[stk.back()] < a[i])
            stk.pop_back();
        Next1[i] = stk.back();
        iNext[stk.back()].push_back(i);
        stk.push_back(i);
    }
    stk.clear();

    /// Next2
    for(int j : iNext[n + 1])   Next2[j] = n + 1;

    stk.push_back(n + 1);
    for(int i = n; i >= 1; i--)
    {
        for(int j : iNext[i])
        {
            int I = 0;

            for(int k = 20; ~k; --k)
                if(I + (1 << k) <= stk.size() && a[stk.end()[-(I + (1 << k))]] < a[j])
                    I += (1 << k);

            Next2[j] = stk.end()[- ++I];
        }

        while(!stk.empty() && a[stk.back()] < a[i])
            stk.pop_back();
        stk.push_back(i);
    }
    stk.clear();

    ll Ans = 0;

    for(int i = 1; i <= n; i++)
    {
        ll Ways1 = (ll) (i - Last1[i]) * (Next2[i] - Next1[i]);
        ll Ways2 = (ll) (Next1[i] - i) * (Last1[i] - Last2[i]);

        Ans += (ll) a[i] * (Ways1 + Ways2);
    }

    cout << Ans << endl;
}
