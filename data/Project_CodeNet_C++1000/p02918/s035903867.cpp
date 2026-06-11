#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using uint = unsigned int;

int main() {

    int N, K; cin >> N >> K;
    string S; cin >> S;
    if (N == 1) {
        cout << 0 << endl;
        return 0;
    }

    int happiness = 0;
    for (size_t i = 0; i<(S.size()-1); i++) {
        if (S[i] == S[i+1]) happiness++;
    }
    if (happiness == (N - 1) ) {
        cout << happiness << endl;
        return 0;
    }

    int rotate = 0;
    uint left = 0;
    uint right = S.size() - 1;
    // ratate == k で終了
    while (rotate < K) {

        uint diff = 0;
        while ((left + diff) < S.size()) {
            if (S[left] != S[left + diff] ) break;
            ++diff;
        }
        if ((left + diff) == S.size()) break;
        else left = left + diff;

        diff = 0;
        while (right  >= diff) {
            if (S[right] != S[right - diff] ) break;
            ++diff;
        }
        if (right < diff) break;
        else right = right - diff;

        if (left < right) {
            happiness += 2;
        }
        else if (left == right) {
            happiness += 2;
            break;
        }
        else {
            happiness += 1;
            break;
        }

        ++rotate;
        if (happiness == N - 1) break;
    }

    cout << happiness << endl;
}

