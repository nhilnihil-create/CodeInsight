#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    long long K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    map<int, int> mp;
    int next = 0, cnt = 1;
    mp[next] = cnt;
    while (cnt <= K) {
        next = A[next];
        cnt++;
        if (mp[next] != 0) break;
        mp[next] = cnt;
    }

    if (cnt <= K) {
        K -= mp[next] - 1;
        K %= cnt - mp[next];
        for (int i = 0; i < K; i++) next = A[next];
    }
    next++;

    cout << next << endl;
}