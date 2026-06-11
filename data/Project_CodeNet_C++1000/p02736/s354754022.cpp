#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int N;
vector<int> A;

bool check1() {
    bool res = false;
    for (int i = 0; i < N; i++) {
        if (A[i] % 2 == 0) continue;
        if ((N - 1 & i) == i) res = !res;
    }
    return res;
}

bool check0() {
    for (int i = 0; i < N; i++)
        if (A[i] == 1) return true;
    return false;
}

int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        A[i] = c - '1';
    }
    if (check1())
        cout << 1 << endl;
    else if (check0())
        cout << 0 << endl;
    else {
        for (int i = 0; i < N; i++) A[i] /= 2;
        cout << (check1() ? 2 : 0) << endl;
    }
    return 0;
}