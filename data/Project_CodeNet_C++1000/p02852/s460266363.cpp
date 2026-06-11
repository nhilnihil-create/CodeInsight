#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    vector<int> ans;
    for (int i = N; i >= 0; i--) {
        int nxt = i;
        for (int j = M; j >= 1; j--) {
            if (i - j >= 0 && S[i - j] != '1') {
                nxt = i - j;
                ans.push_back(j);
                break;
            }
        }
        if (nxt == 0)
            break;
        if (nxt == i) {
            cout << -1 << endl;
            return 0;
        }
        i = nxt + 1;
    }
    reverse(ans.begin(), ans.end());
    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
