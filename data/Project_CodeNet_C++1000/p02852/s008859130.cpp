#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;

int main() {
    int N, M;
    string S;
    cin >> N >> M >> S;
    vector<int> ans;
    reverse(all(S));
    int now   = 0;
    bool flag = false;
    while (now <= N && !flag) {
        flag = true;
        for (int i = M; i >= 1; --i) {
            if (now + i > N) continue;
            if (S[now + i] == '0') {
                now = now + i;
                ans.push_back(i);
                flag = false;
                break;
            }
        }
    }

    if(now != N){
        cout << -1 << endl;
        return 0;
    }

    reverse(all(ans));
    for(auto e:ans) cout << e << " ";
    cout << endl;
}