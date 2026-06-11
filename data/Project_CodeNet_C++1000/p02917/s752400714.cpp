#include <bits/stdc++.h>
using namespace std;

void solve(int N, vector<int> B)
{
    int res = 0;
    res += B.at(0);
    for (int i = 0; i < N - 2; i++)
    {
        res += min(B.at(i), B.at(i + 1));
    }
    res += B.at(N - 2);
    cout << res << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> B(N-1);
    for(int i = 0; i < N-1; i++) {
        cin >> B.at(i);
    }
    solve(N, move(B));
    return 0;
}
