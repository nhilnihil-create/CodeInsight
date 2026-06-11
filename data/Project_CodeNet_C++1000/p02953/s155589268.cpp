#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> vec(N);
    vector<int> f(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> vec[i];
    for (int i = N - 1; i > 0; --i)
    {
        if (vec[i - 1] <= vec[i])
            continue;
        if (f[i - 1] == 1)
            continue;
        --vec[i - 1];
        ++f[i - 1];
        if (vec[i - 1] > vec[i])
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}
