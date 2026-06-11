#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t a, int64_t b)
{
    if (a < b)
    {
        swap(a, b);
    }
    while (b != 0)
    {
        int64_t t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int count(int x)
{
    int res = 0;
    while (x % 2 == 0)
    {
        res++;
        x >>= 1;
    }
    return res;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a.at(i);
        a.at(i) /= 2;
    }

    int c = count(a.at(0));
    for (int i = 0; i < N; i++)
    {
        if (count(a.at(i)) != c)
        {
            cout << 0 << endl;
            return 0;
        }
        a.at(i) >>= c;
    }
    M >>= c;

    int64_t l = 1;
    for (int i = 0; i < N; i++)
    {
        int64_t g = gcd(l, a.at(i));
        l = l / g * a.at(i);
        if (l > M)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << (M / l + 1) / 2 << endl;
    return 0;
}
