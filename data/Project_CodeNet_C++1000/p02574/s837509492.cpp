#include <bits/stdc++.h>
using namespace std;

vector<int> divs[1000005];
int cnt[1000005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i <= 1000000; ++i) {
        for (int m = i; m <= 1000000; m += i) {
            divs[m].push_back(i);
        }
    }

    int N;
    cin >> N;
    vector<int> A(N);
    for (int& e : A) cin >> e;


    bool pair = 1;

    for (int i = 0; i < N; ++i) {
        for (int d : divs[A[i]]) {
            if (cnt[d] > 0) {
                pair = 0;
            }
            cnt[d]++;
        }
    }

    if (pair) {
        cout << "pairwise coprime" << endl;
    } else {
        for (int v = 1; v <= 1000000; ++v) {
            // cout << kv.first << " " << kv.second <<endl;
            if (cnt[v] == N) {
                cout << "not coprime" << endl;
                return 0;
            }
        }
        cout << "setwise coprime" << endl;
    }
}