#include <iostream>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        int dig[3] = {i/100, i/10%10, i%10};
        int flag = 0;
        for (int j = 0; j < N; j++) {
            if (dig[flag] + '0' == s[j]) flag++;
            if (flag == 3) break;
        }
        if (flag == 3) ans++;
    }
    cout << ans << endl;
}