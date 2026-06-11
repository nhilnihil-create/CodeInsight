#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define MOD 1000000007

int K;
vector<vector<int>> to;

ll calc(int current, int parent)
{
    if (parent < 0)
    {
        ll ret = K;

        for (int i = 0; i < to[current].size(); i++)
        {
            ret = (ret * (K - i - 1)) % MOD;
        }
        for (int i : to[current])
        {
            ret = (ret * calc(i, current)) % MOD;
        }
        return ret;
    }
    else
    {
        ll ret = 1;

        for (int i = 0; i < to[current].size() - 1; i++)
        {
            ret = (ret * (K - i - 2)) % MOD;
        }
        for (int i : to[current])
        {
            if (i != parent)
            {
                ret = (ret * calc(i, current)) % MOD;
            }
        }
        return ret;
    }
}
int main()
{
    int N;

    cin >> N >> K;

    to = vector<vector<int>>(N + 1, vector<int>());

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;

        cin >> a >> b;

        to[a].push_back(b);
        to[b].push_back(a);
    }
    cout << calc(1, -1) << endl;

    return 0;
}