#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> P(N, 0);
    for (int i = 0; i < Q; i++)
    {
        int a;
        cin >> a;
        a--;
        P[a]++;
    }
    
    for (int i = 0; i < N; i++)
    {
        if (P[i] + K - Q <= 0)
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}