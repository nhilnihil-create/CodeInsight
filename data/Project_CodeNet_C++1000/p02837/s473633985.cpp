// 6/23 解き直し
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

int main() {
    int N;
    cin >> N;

    vector<vector<P>> states(N);

    rep(i, N) {
        int a;
        cin >> a;

        rep(j, a) {
            int x, y;
            cin >> x >> y;
            x--;
            states[i].push_back({x, y});
        }
    }

    // cout << "here?" << endl;

    int res = 0;

    rep(div, 1<<N) {
        bool be = true;
        vector<int> honests(N, -1);
        int num = 0;

        rep(i, N) {
            if (div>>i&1) {
                // i人目が正直なら
                // cout << "1";  // << endl;
                num += 1;

                for (auto p : states[i]) {
                    // if (honests[p.first] == -1) {
                    //     honests[p.first] = p.second;
                    // } else {
                    //     if (honests[p.first] != p.second) {
                    //         be = false;
                    //         break;
                    //     }
                    // }
                    // printf("p.first, second = %d, %d\n", p.first, p.second);
                    // printf("div>>p.first&1=%d\n", div>>p.first&0);

                    if ((div>>p.first&1 && p.second!=1) || !(div>>p.first&1) && p.second==1) {
                        // cout << "here?2" << endl;
                        be = false;
                        break;
                    }
                }

            } else {
                // cout << "0";  // << endl;
            }
            
        }
        // cout << endl;

        if (be) {
            res = max(res, num);
        }
    }

    cout << res << endl;
}