#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        string num = "";
        int x = i;
        for (int j = 0; j < 3; j++) {
            num = (char)('0' + x % 10) + num;
            x /= 10;
        }

        int k = 0;
        for (int j = 0; j < N; j++) {
            if (S[j] == num[k]) k++;
        }
        
        if (k == 3) ans++;
    }

    cout << ans << endl;
}