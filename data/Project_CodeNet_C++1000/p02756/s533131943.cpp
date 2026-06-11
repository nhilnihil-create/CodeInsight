#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    string S;
    int Q;
    cin >> S >> Q;
    bool flip = false;
    string head;
    string tail;
    for (int i = 0; i < Q; ++i) {
        int T;
        cin >> T;
        if (T == 1) flip = !flip;
        else {
            int F;
            cin >> F;
            if (F == 1) {
                char C;
                cin >> C;
                if (flip) tail += C;
                else head += C;
            }
            if (F == 2) {
                char C;
                cin >> C;
                if (flip) head += C;
                else tail += C;
            }
        }
    }
    if (flip) {
        reverse(tail.begin(), tail.end());
        reverse(S.begin(), S.end());
        cout << tail + S + head << endl;
    } else {
        reverse(head.begin(), head.end());
        cout << head + S + tail << endl;
    }
    return 0;
}