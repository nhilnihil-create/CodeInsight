
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<vector<int>> in(N, vector<int>(3, 0));
    for (int i = 0; i < N; ++i) cin >> in[i][0];
    for (int i = 0; i < N; ++i) {
        int input; cin >> input;
        for (int j = 0; j < N; ++j) {
            if (in[j][0] - 1 == i) in[j][1] = input;
        }
    }
    for (int i = 0; i < N - 1; ++i) {
        int input; cin >> input;
        for (int j = 0; j < N; ++j) {
            if (in[j][0] - 1 == i) {
                in[j][2] = input;
                break;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int now = in[i][0];
        sum += in[i][1];
        if (in[i][2] != 0 && i != N - 1) {
            if (now + 1 == in[i + 1][0]) {
                sum += in[i][2];
            }
        }
    }
    printf("%d\n", sum);
}