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
    vector<int> A(9);
    for (int i = 0; i < 9; i++) {
        cin >> A[i];
    }
    int N;
    cin >> N;
    vector<int> B(N);
    vector<int> bingo(9, 0);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        for (int j = 0; j < 9; j++) {
            if (A[j] == B[i]) bingo[j] = 1;
        }
    }

    bool yes = false;
    for (int i = 0; i < 3; i++) {
        if (bingo[i] && bingo[i + 3] && bingo[i + 6]) yes = true;
        if (bingo[3 * i] && bingo[3 * i + 1] && bingo[3 * i + 2]) yes = true;
        if (bingo[0] && bingo[4] && bingo[8]) yes = true;
        if (bingo[2] && bingo[4] && bingo[6]) yes = true;
    }
    if (yes)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
