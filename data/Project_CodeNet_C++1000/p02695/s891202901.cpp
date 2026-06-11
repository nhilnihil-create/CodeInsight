#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
vector<long long> a, b, c, d;

long long score(const vector<int> &A) {
    long long res = 0;
    for (int i = 0; i < Q; ++i) if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
    return res;
}

long long dfs(vector<int> &A) {
    if (A.size() == N) {
        return score(A);
    }
    long long res = 0;
    int plast = (A.empty() ? 0 : A.back());
    for (int add = plast; add < M; ++add) {
        A.push_back(add);
        res = max(res, dfs(A));
        A.pop_back();
    }
    return res;
}

int main() {
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        a[i]-= 1;b[i]-=1;
    }
    vector<int> A;
    cout << dfs(A) << endl;
}