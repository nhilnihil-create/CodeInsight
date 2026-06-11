#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, s, e) for (int i = s; i < e; i++)
#define endl '\n'
bool notInArray(int a, vector<int> A, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (a == A[i])
            return false;
    }
    return true;
}
int main()
{
    int X, N;
    cin >> X >> N;
    vector<int> P(N);
    int res = 1000;
    int ans = X;
    rep(i, 0, N) cin >> P[i];
    rep(i, 0, 102)
    {
        if (notInArray(i, P, P.size()))
        {
            if (abs(X - i) < res)
            {
                res = abs(X - i);
                ans = i;
            }
        }
    }
    cout << ans << endl;
}
