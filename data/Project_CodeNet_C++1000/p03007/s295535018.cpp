#include <bits/stdc++.h>
using namespace std;

void solve(int N, vector<int> A)
{
    sort(A.begin(), A.end());
    int l = 0, r = 1;
    for (int i = 1; i < N - 1; i++)
    {
        if (A.at(i) >= 0)
            break;
        l++;
        r++;
    }
    int res = 0;
    for (int i = 0; i <= l; i++)
        res -= A.at(i);
    for (int i = r; i < N; i++)
        res += A.at(i);
    cout << res << endl;

    int current;
    if (r == N - 1)
    {
        cout << A.at(r) << " " << A.at(l) << endl;
        current = A.at(r) - A.at(l);
    }
    else
    {
        cout << A.at(l) << " " << A.at(r) << endl;
        current = A.at(l) - A.at(r);
    }
    l--;
    r++;
    while (r < N)
    {
        if (r == N - 1)
        {
            cout << A.at(r) << " " << current << endl;
            current = A.at(r) - current;
        }
        else
        {
            cout << current << " " << A.at(r) << endl;
            current -= A.at(r);
        }
        r++;
    }
    while (l >= 0)
    {
        cout << current << " " << A.at(l) << endl;
        current -= A.at(l);
        l--;
    }
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
