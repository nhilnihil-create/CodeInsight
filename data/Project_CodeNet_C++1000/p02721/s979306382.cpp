// 6/18 振り返り
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    vector<int> L(K), R(K);

    int day = 0;
    int k = 0;
    while (k < K) {
        if (S[day] == 'o') {
            L[k++] = day;
            day += (C + 1);
            // k++;
        } else {
            day += 1;
        }
    }
    // rep(i, K) {
    //     cout << L[i] << endl;
    // }

    day = N - 1;
    k = K - 1;
    while (k >= 0) {
        if (S[day] == 'o') {
            R[k--] = day;
            day -= (C + 1);
        } else {
            day -= 1;
        }
    }

    rep(i, K) {
        if (R[i] == L[i]) {
            cout << R[i] + 1 << endl;
        }
    }
}