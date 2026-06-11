#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;



int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<long long> T(2, 0);
    vector<vector<long long>> S(2, vector<long long>(2, 0));

    for (int i = 0; i < 2; ++i) {
        cin >> T[i];
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> S[i][j];
        }
    }

    long long PT = T[0] + T[1];
    vector<long long> D(2, 0);
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            D[i] += S[i][j] * T[j];
        }
    }

    if (D[0] == D[1] || S[0][0] == S[1][0]) {
        cout << "infinity\n";
        return 0;
    }

    if (S[0][0] > S[1][0]) {
        swap(S[0], S[1]);
        swap(D[0], D[1]);
    }
    
    if (D[0] < D[1]) {
        cout << 0 << '\n';
        return 0;
    }

    long long res = 0;
    long long diff = D[0] - D[1];
    long long A = (S[1][0] - S[0][0]) * T[0];
    res += 1;
    res += (A / diff) * 2;
    if (A % diff == 0) {
        --res;
    }

    cout << res << '\n';

    return 0;
}