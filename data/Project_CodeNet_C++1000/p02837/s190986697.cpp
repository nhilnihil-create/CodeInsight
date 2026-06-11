#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

#define rep(i, n) for (int i = 0; (i) < (n); (i)++)
using namespace std;
using ll = long long;
int testimony[15][15];

int main(void) {
    rep(i, 15)
        rep(j, 15)
            testimony[i][j] = -1;

    int N; cin >> N;

    rep(i, N) {
        int A; cin >> A;
        rep(j, A) {
            int x, y;
            cin >> x >> y;
            testimony[i][x-1] = y;
        }
    }

    int ret = 0;
    for(int bit=0; bit < (1 << N); ++bit) {
        // bit=1: Honest
        // bit=0: Unkind
        int num = 0;
        bool ok = true;
        rep(i, N) {
            if (((1 << i) & bit) == 0) {
                // we do not respect unkind person
                continue;
            }

            // check if he says truth
            rep(j, N) {
                if(testimony[i][j] == -1) {
                    continue;
                }
                auto b = ((1 << j) & bit) != 0;
                if(testimony[i][j] != b) {
                    ok = false;
                    break;
                }
            }
            if(!ok) {
                break;
            }
        }
        if(ok) {
//            cout << "ok:" << bit << endl;
            ret = max(ret, __builtin_popcount(bit));
        }
//        cout << "bit=" << bit << ", num=" << num << endl;
    }
    cout << ret << endl;

#if 0
    rep(i, N) {
        rep(j, N) {
            cout << testimony[i][j] << ", ";
        }
        cout << endl;
    }
#endif
    return 0;
}
