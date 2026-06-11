#include <bits/stdc++.h>
//#define int long long

using namespace std;

const int N = 1e6 + 9;
vector <int> prime;
bool used[N];


void calc() {
    for (int i = 4; i < N; i += 2) used[i] = 1;
    for (int i = 3; i * i < N; i += 2) {
        if (used[i]) continue;
        for (int j = i * i; j < N; j += i) used[j] = 1;
    }
    prime.push_back(2);
    for (int i = 3; i < N; i += 2) {
        if (!used[i]) prime.push_back(i);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; ++i) cin >> data[i];
    calc();
    vector <int> cnt(N, 0);
    int fl = 1;
    for (int i = 0; i < n; ++i) {
        int tmp = data[i];
        for (auto a : prime) {
            if (a * a > tmp) break;
            if (tmp % a == 0) {
                ++cnt[a];
                while (tmp % a == 0) tmp /= a;
            }
        }
        if (tmp > 1) ++cnt[tmp];
    }
    for (int i = 0; i < N; ++i) {
        if (cnt[i] > 1) fl = 0;
    }
    if (fl) {
        cout << "pairwise coprime";
        return 0;
    }
    int b = data[0];
    for (int i = 1; i < n; ++i) b = __gcd(b, data[i]);
    if (b == 1) {
        cout << "setwise coprime";
        return 0;
    }
    cout << "not coprime";
    return 0;
}
