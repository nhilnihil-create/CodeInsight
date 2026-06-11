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
    int N;
    cin >> N;

    double X = N / 1.08;
    int X_floor = (int)(floor(X));
    int X_ceil  = (int)(ceil(X));

    int N_floor = (int)(floor(X_floor * 1.08));
    int N_ceil = (int)(floor(X_ceil * 1.08));

    if (N_floor == N)
        cout << X_floor << endl;
    else if (N_ceil == N)
        cout << X_ceil << endl;
    else
        cout << ":(" << endl;

    return 0;
}