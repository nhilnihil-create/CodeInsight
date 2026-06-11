#include <iostream>
#include <cstring>
using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)

/*
    state := 0 foots are on the earth, 1 stepping up,
             2 foots are on the step, 3 stepping down.
*/

int n, state = 0, ans = 0;
string s, prefoot = "";

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (cin >> n, n) {
        state = ans = 0;
        prefoot = "";
        
        rep(i,n) {
            cin >> s;
            if (state == 0) {
                prefoot = s;
                state = 1;
            } else if (state == 1) {
                if (prefoot == "lu") {
                    if (s == "ru") {
                        ans++;
                        state = 2;
                    } else {
                        state = 0;
                    }
                } else if (prefoot == "ru") {
                    if (s == "lu") {
                        ans++;
                        state = 2;
                    } else {
                        state = 0;
                    }
                }
            } else if (state == 2) {
                prefoot = s;
                state = 3;
            } else if (state == 3) {
                if (prefoot == "ld") {
                    if (s == "rd") {
                        ans++;
                        state = 0;
                    } else {
                        state = 2;
                    }
                } else if (prefoot == "rd") {
                    if (s == "ld") {
                        ans++;
                        state = 0;
                    } else {
                        state = 2;
                    }
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}