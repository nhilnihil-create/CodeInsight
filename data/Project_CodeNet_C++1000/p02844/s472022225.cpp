#include <iostream>
using namespace std;
const int INF = 1000000000;

int main() {
    int N; 
    string S;
    cin >> N >> S;
    int ans = 0;
    for (int i = 0; i <= 999; i++) {
        int dig[3] = {i / 100, i / 10 % 10, i % 10};
        int flag = 0;
        for (int j = 0; j < N; j++) {
            if (S[j] - '0' == dig[flag]) flag++;
            if (flag == 3) break;
        }
        if (flag == 3) ans++;
    }
    cout << ans << endl;
    return 0;
}