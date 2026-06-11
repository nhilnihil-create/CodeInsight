#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
    /* input */
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (auto& ai : A)
        cin >> ai;
    for (auto& bi : B)
        cin >> bi;
    /* solve */
    priority_queue<pair<int, int>> dis_idx;
    for (int i = 0; i < N; ++i){
        if (B[i] < A[i]){
            cout << -1 << endl;
            exit(0);
        }
        int tmp = B[i] - (B[(i - 1 + N) % N] + B[(i + 1) % N] + A[i]);
        if (tmp >= 0) dis_idx.push({tmp, i});
    }
    ll op = 0;
    while (!dis_idx.empty()){
        int idx = dis_idx.top().second;
        dis_idx.pop();
        int dis = B[idx] - A[idx];
        int one_op = B[(idx - 1 + N) % N] + B[(idx + 1) % N];
        if (dis < one_op){
            cout << -1 << endl;
            exit(0);
        }
        op += dis / one_op;
        B[idx] = A[idx] + (dis % one_op);
        for (int i = idx - 1; i <= idx + 1; ++i){
            int tmp = B[(i + N) % N] - (B[(i - 1 + N) % N] + B[(i + 1) % N] + A[(i + N) % N]);
            if (tmp >= 0) dis_idx.push({tmp, (i + N) % N});
        }
        /* for (auto bi : B)
            cout << bi << " ";
        cout << endl; */
    }
    bool ok = true;
    for (int i = 0; i < N; ++i)
        ok &= A[i] == B[i];
    cout << (ok ? op : -1) << endl;
    return 0;
}