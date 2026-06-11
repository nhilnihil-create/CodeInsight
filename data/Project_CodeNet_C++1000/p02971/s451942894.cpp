#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll N;
    cin >> N;
    vector<ll> A;
    vector<ll> B;
    for (int i = 0; i < N; ++i)
    {
        ll temp;
        cin >> temp;
        A.push_back(temp);
        B.push_back(temp);
    }

    sort(B.begin(), B.end());

    for (auto a : A)
    {
        if (a == B[N - 1])
        {
            cout << B[N - 2] << endl;
        }
        else
        {
            cout << B[N - 1] << endl;
        }
    }
}
