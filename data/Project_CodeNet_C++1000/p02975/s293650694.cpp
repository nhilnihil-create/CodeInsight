#include <bits/stdc++.h>
using namespace std;

int main() {
    long N;
    cin >> N;
    bool ans = true;
    bool b = false;
    if (N % 3 != 0) {
        for (int i = 0; i < N; i++) {
            long a;
            cin >> a;
            if (a != 0) {
                ans = false;
            }
        }
    }
    else {
        map<long, long> data;
        priority_queue<long> keep;
        for (int i = 0; i < N; i++) {
            long a;
            cin >> a;
            if (!data.count(a)) {
                data[a] = 1;
                keep.push(a);
            }
            else {
                data[a] = data.at(a) + 1;
            }
        }
        if (data.size() >= 4) {
            ans = false;
        }
        else if (data.size() == 1) {
            if (keep.top() != 0) {
                ans = false;
            }
        }
        else if (data.size() == 2) {
            if (data.at(keep.top()) != N * 2 / 3) {
                ans = false;
            }
            keep.pop();
            if (keep.top() != 0) {
                ans = false;
            }
            if (data.at(keep.top()) != N / 3) {
                ans = false;
            }
        }
        else if (data.size() == 3) {
            long x, y, z;
            x = keep.top();
            keep.pop();
            y = keep.top();
            keep.pop();
            z = keep.top();
            keep.pop();
            if (data.at(x) != N / 3 || data.at(y) != N / 3 || data.at(z) != N / 3) {
                ans = false;
            }
            if ((x ^ y ^ z) != 0) {
                ans = false;
            }
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}