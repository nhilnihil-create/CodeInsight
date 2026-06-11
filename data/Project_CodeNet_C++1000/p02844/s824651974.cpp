#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    string S;
    cin >> N >> S;
    int U1[10] = {}, U2[100] = {}, U3[1000] = {};
    for (int i = 0; i < N; ++i) {
        int s = S.at(i) - '0';
        for (int t = 0; t < 100; ++t) {
            if (U2[t] > 0)
                ++U3[10 * t + s];
        }
        for (int t = 0; t < 10; ++t) {
            if (U1[t] > 0)
                ++U2[10 * t + s];
        }
        ++U1[s];
    }
    int cnt = 0;
    for (int t = 0; t < 1000; ++t) {
        if (U3[t] > 0)
            ++cnt;
    }
    cout << cnt << endl;
}
