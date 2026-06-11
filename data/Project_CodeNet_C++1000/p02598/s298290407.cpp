#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(double length, int K, vector<int> &logs) {
    int count = 0;
    for (auto log: logs) {
        count += (ceil((double)log / length) - 1);
        if (count > K) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, K;
    cin >> N >> K;    
    vector<int> logs;
    for (int i = 0; i < N; i++) {
        int log;
        cin >> log;
        logs.push_back(log);
    }

    int left = 1, right = pow(10,9);
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid, K, logs)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << left << endl;
    return 0;
}