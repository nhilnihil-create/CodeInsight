#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N, K;
    cin >> N >> K;
    int upper = (N - 1) * (N - 2) / 2 - K;
    if (upper < 0) {
        cout << -1 << '\n';
        return 0;
    }
    upper = N * (N - 1) / 2 - K;
    cout << upper << '\n';
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (upper <= 0) return 0;
            cout << i + 1 << ' ' << j + 1 << '\n';
            upper--;
        }
    }
}
