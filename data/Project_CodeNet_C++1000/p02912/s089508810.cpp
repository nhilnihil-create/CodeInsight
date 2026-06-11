#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;

    map<ll, ll> A;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A[tmp]++;
    }

    while (M != 0) {
        int max = A.rbegin()->first;
        A[max]--;
        if (A[max] == 0) {
            A.erase(max);
        }
        max = max / 2;
        A[max]++;
        M--;
    }

    ll output = 0;
    for (auto var : A) {
        output += var.first * var.second;
    }

    cout << output << endl;

    return 0;
}
