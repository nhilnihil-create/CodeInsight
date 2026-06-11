#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<int, int>;
using namespace std;

#define INF ((1<<30)-1)
#define LLINF (1LL<<60)
#define EPS (1e-10)

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    set<string> st;
    for (int i = 0; i < 1000; ++i) {
        string t = to_string(i);
        int sz = t.size();
        rep(i, 3 - sz) {
            t = "0" + t;
        }
        int cur = 0;
        rep(j, S.size()) {
            if (cur >= 3) break;
            if (S[j] == t[cur]) cur++;
        }
        if (cur == 3) st.insert(t);
    }

    cout << st.size() << endl;
}
