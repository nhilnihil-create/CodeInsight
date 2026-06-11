#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int64_t, int64_t>> factors;

factors p_fac(int64_t n)
{
    factors res;
    for (int64_t p = 2; p * p <= n; p++)
    {
        if (n % p == 0)
        {
            int64_t e = 0;
            while (n % p == 0)
            {
                n /= p;
                e += 1;
            }
            res.push_back(make_pair(p, e));
        }
    }
    if (n != 1)
    {
        res.push_back(make_pair(n, 1));
    }
    return res;
}

void solve(int N, vector<int> A)
{
    vector<factors> A_fac(N);
    for (int i = 0; i < N; i++)
    {
        A_fac.at(i) = p_fac(A.at(i));
    }

    set<int64_t> fac_union;
    for (auto &&f : A_fac.at(0))
    {
        fac_union.insert(f.first);
    }
    int64_t g = A.at(0);

    bool is_pairwise = true;
    for (int i = 1; i < N; i++)
    {
        if (is_pairwise)
        {
            for (auto &&f : A_fac.at(i))
            {
                if (fac_union.count(f.first) > 0)
                {
                    is_pairwise = false;
                    break;
                }
                fac_union.insert(f.first);
            }
        }
        g = gcd(g, A.at(i));
    }

    if (is_pairwise)
        cout << "pairwise coprime" << endl;
    else if (g == 1)
        cout << "setwise coprime" << endl;
    else
        cout << "not coprime" << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }
    solve(N, move(A));
    return 0;
}
