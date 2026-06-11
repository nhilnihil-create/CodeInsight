#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define MAXN 1000001

using namespace std;

int spf[MAXN];
unordered_map<int, bool> factors;

void sieve()
{
    for (int i = 1; i < MAXN; ++i)
        spf[i] = ((i & 1) ? i : 2);

    for (int i = 3; i * i < MAXN; ++i)
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
}

void check(string &result, int x)
{
    if (result == "setwise coprime")
        return;

    unordered_set<int> freg;

    while (x != 1)
    {
        if (factors[spf[x]] && result == "pairwise coprime")
        {
            result = "setwise coprime";
            return;
        }
        freg.insert(spf[x]);
        x /= spf[x];
    }

    for (unordered_set<int>::iterator it = freg.begin(); it != freg.end(); ++it)
        factors[*it] = true;
}

int main()
{

    sieve();

    ios_base::sync_with_stdio(false);

    int size;
    cin >> size;

    if (size == 1)
        cout << "not coprime";
    else
    {
        string result = "pairwise coprime";
        int gcd = 0, x;

        while (size--)
        {
            cin >> x;
            if (gcd != 0)
                gcd = __gcd(gcd, x);
            else
                gcd = x;
            check(result, x);
        }
        cout << ((gcd == 1) ? result : "not coprime");
    }

    return 0;
}