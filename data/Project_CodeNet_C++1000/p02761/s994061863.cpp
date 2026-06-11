#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    long long int N, M;
    cin >> N >> M;
    bool key = true;

    vector<long long int>ans(N);
    long long int s, c;

    for (int i = 0; i < M; i++) {
        cin >> s >> c;
        if (N != 1 && s == 1 && c== 0) {
            key = false;
        }
        if (ans[s - 1] == NULL) {
            ans[s - 1] = c;
        }
        else {
            if (ans[s - 1] != c) {
                key = false;
            }
        }
    }


    if (key == true) {
        for (int i = 0; i < N; i++) {
            if (ans[i] == NULL) {
                if (i == 0 && N != 1) {
                    cout << 1;
                }
                else {
                    cout << 0;
                }
            }
            else {
                cout << ans[i];
            }
        }
    }
    else {
        cout << "-1";
    }

    return 0;
}