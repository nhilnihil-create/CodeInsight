#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    
    reverse(S.begin(), S.end());
    vector<int> ans;
    int now = 0;
    while (true) {
        if (N - now <= M) {
            ans.push_back(N - now);
            break;
        }
        bool susumu = false;
        for (int i = M; i > 0; --i) {
            if (S[now + i] == '0') {
                ans.push_back(i);
                now += i;
                susumu = true;
                break;
            }
        }
        if (!susumu) {
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    rep(i, ans.size() - 1) cout << ans[i] << " ";
    cout << ans[ans.size() - 1] << endl;
    return 0;
}
