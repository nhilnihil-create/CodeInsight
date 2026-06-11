#include <bits/stdc++.h>
using namespace std;

set<int> divisors(int n)
{
    set<int> res;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int q = n / i;
            res.insert(i);
            res.insert(q);
        }
    }
    return res;
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a.at(i);
    }

    vector<int> res;
    vector<int> cnt(N);
    for (int i = N; i > 0; i--)
    {
        if (cnt.at(i - 1) % 2 != a.at(i - 1))
        {
            res.push_back(i);
            for (auto &&j : divisors(i))
            {
                cnt.at(j - 1)++;
            }
        }
    }

    cout << res.size() << endl;
    for (auto &&i : res)
    {
        cout << i << " ";
    }
    cout << endl;
}