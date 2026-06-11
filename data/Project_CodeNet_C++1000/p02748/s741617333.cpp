#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A);
    int min_ai = INT_MAX;
    for (int i = 0; i < A; i++)
    {
        cin >> a.at(i);
        min_ai = min(min_ai, a.at(i));
    }
    vector<int> b(B);
    int min_bi = INT_MAX;
    for (int i = 0; i < B; i++)
    {
        cin >> b.at(i);
        min_bi = min(min_bi, b.at(i));
    }

    int res = min_ai + min_bi;
    int xi, yi, ci;
    for (int i = 0; i < M; i++)
    {
        cin >> xi >> yi >> ci;
        xi--;
        yi--;
        res = min(res, a.at(xi) + b.at(yi) - ci);
    }
    cout << res << endl;
}