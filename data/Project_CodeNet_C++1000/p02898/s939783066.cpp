#include <bits/stdc++.h>
using namespace std;

void solve(int N, int K, vector<int> h)
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        if (h.at(i) >= K)
            res++;
    }
    cout << res << endl;
}

int main()
{
    int N;
    cin >> N;
    int K;
    cin >> K;
    vector<int> h(N);
    for(int i = 0; i < N; i++) {
        cin >> h.at(i);
    }
    solve(N, K, move(h));
    return 0;
}
