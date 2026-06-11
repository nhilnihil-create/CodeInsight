#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reps(i, f, n) for (int i = (f); i < (n); i++)
ll const INF = 1LL << 60;

int main() {
    string S;
    cin >> S;

    if (S.length() % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }

    bool flg = true;
    for (int i = 0; i < S.length(); i += 2) {
        if (!(S[i] == 'h' && S[i + 1] == 'i')) {
            flg = false;
            break;
        }
    }

    if (flg)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}