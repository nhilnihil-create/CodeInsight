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
    deque<char> dq(S.size());
    for (int i = 0; i < S.size(); ++i) dq[i] = S[i];
    bool flip = false;
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
                if (flip) dq.push_back(C);
                else dq.push_front(C);
            }
            if (F == 2) {
                char C;
                cin >> C;
                if (flip) dq.push_front(C);
                else dq.push_back(C);
            }
        }
    }
    if (flip) reverse(dq.begin(), dq.end());
    for (auto&& ele : dq) cout << ele;
    cout << endl;
    
    return 0;
}