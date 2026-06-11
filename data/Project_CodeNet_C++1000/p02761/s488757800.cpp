#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    if (N == 1 && M == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> digit(N, -1);
    for (int i = 0; i < M; i++) {
        int s, c;
        cin >> s >> c;
        if (digit[s - 1] != -1 && digit[s - 1] != c) {
            cout << -1 << endl;
            return 0;
        } else if (s == 1 && c == 0 && N != 1) {
            cout << -1 << endl;
            return 0;
        } else {
            digit[s - 1] = c;
        }
    }

    int output = 0;
    for (int i = 0; i < N; i++) {
        if (digit[i] == -1 && i == 0) {
            output += pow(10, N - i - 1);
        } else if (digit[i] != -1) {
            output += pow(10, N - i - 1) * digit[i];
        }
    }

    cout << output << endl;

    return 0;
}
