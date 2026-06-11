#include <iostream>

using namespace std;

int main(void)
{
    string S, T;

    cin >> S >> T;
    int m, ans = 0x7FFFFFFF;
    for (int i = 0; i < S.size(); i++) {
        m = 0;
        bool f = false;
        for (int j = 0; j < T.size(); j++) {
            if (i + j >= S.size()) {
                f = true;
                break;
            }
            if (S[i + j] != T[j]) {
                m++;
            }
        }
        if (!f) {
            ans = min(ans, m);
        }
    }
    cout << ans << endl;
    return 0;
}