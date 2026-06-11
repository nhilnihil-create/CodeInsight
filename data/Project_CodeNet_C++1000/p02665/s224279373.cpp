//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;


void solve() {
    int N; cin >> N;
    vector<long long> A(N+1);
    for (int i = 0; i < N+1; i++) cin >> A[i];

    if (N == 0) {
        if (A[0] == 1) cout << 1 << endl;
        else cout << -1 << endl;
        return;
    }
    else {
        if (A[0] > 0) {
            cout << -1 << endl;
            return;
        }
    }

    vector<long long> max_node(N+1);
    max_node[N] = A[N];
    for (int i = N-1; i >= 0; i--)  {
        max_node[i] = max_node[i+1] + A[i];
    }

    long long sum = 0;
    long long node = 1;
    for (int i = 0; i < N+1; i++) {
        node = min(node, max_node[i]);
        sum += node;
        node = (node - A[i]) * 2;
        //cout << node << endl;
        if (node < 0) {
            cout << -1 << endl;
            return;
        }
    }

    cout << sum << endl;
}


int main() {
    solve();
    return 0;
}