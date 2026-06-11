#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    string S; cin >> S;

    int ans = 0;
    bool is_reverse = false;
    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        if (!is_reverse && S[i] == S[i + 1]) {
            ans++;
            continue;
        }
        if (cnt < K && !is_reverse && S[i] != S[i + 1]) {
            is_reverse = true;
            ans++;
            cnt++;
            continue;
        }
        if (is_reverse && S[i] == S[i + 1]) {
            ans++; 
            continue;
        }
        if (is_reverse && S[i] != S[i + 1]) {
            is_reverse = false;
            ans++;
            continue;
        }
    }
    cout << ans << endl;
}
