#include <iostream>
#include<string>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    int lenS = S.size();
    int lenT = T.size();
    int count, ans;
    for (int i = 0; i <= lenS - lenT; i++) {
        count = 0;
        for (int j = 0; j < lenT; j++) {
            if (S[i + j] != T[j]) {
                count++;
            }
        }
        if (i == 0) ans = count;
        ans = min(ans, count);
    }
    cout << ans << endl;
    return 0;
}