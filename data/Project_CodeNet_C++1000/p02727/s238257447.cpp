#include <iostream>
#include <set>
#include <vector>
#include <iomanip>
#include <deque>

#include <algorithm>

#include <cfenv>
#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;
int main()
{

    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    vector<ll> As(A);
    vector<ll> Bs(B);
    vector<ll> Cs(C);

    vector<ll> Ds(0);

    for (int i = 0; i < A; i++)
    {

        cin >> As[i];
    }

    for (int i = 0; i < B; i++)
    {

        cin >> Bs[i];
    }

    for (int i = 0; i < C; i++)
    {

        cin >> Cs[i];
    }

    sort(As.begin(), As.end(), greater<ll>());
    sort(Bs.begin(), Bs.end(), greater<ll>());
    sort(Cs.begin(), Cs.end(), greater<ll>());

    ll sum = 0;

    for (int i = 0; i < X; i++)
    {

        sum += As[i];

        Ds.push_back(As[i]);
    }

    for (int i = 0; i < Y; i++)
    {

        sum += Bs[i];

        Ds.push_back(Bs[i]);
    }

    sort(Ds.begin(), Ds.end());

    for (int i = 0; i < Y + X; i++)
    {

        if (i == C)
        {

            break;
        }

        if (Ds[i] <= Cs[i])
        {

            sum = sum + Cs[i] - Ds[i];
        }
        else
        {
            break;
        }
    }

    cout << sum << endl;

    return 0;
}