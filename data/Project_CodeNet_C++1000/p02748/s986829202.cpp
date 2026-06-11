#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <math.h> // sqrt
using namespace std;

int main() {
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> fri(A);
    vector<int> mic(B);
    for (int i = 0; i < A; i++) {
        cin >> fri.at(i);
    }
    for (int i = 0;  i < B; i++) {
        cin >> mic.at(i);
    }
    vector<vector<int>> off(M, vector<int>(3));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> off.at(i).at(j);
        }
    }
    int sum;
    int ans = 200000;
    for (int i = 0; i < M; i++) {
        sum = fri.at(off.at(i).at(0) - 1) + mic.at(off.at(i).at(1) - 1) - off.at(i).at(2);
        ans = min(ans, sum);
    }
    int minf = fri.at(0);
    int minm = mic.at(0);
    int f = 0;
    int m = 0;
    for (int i = 1; i < A; i++) {
        if (fri.at(i) < minf) {
            minf = fri.at(i);
            f = i;
        }
    }
    for (int i = 1; i < B; i++) {
        if (mic.at(i) < minm) {
            minm = mic.at(i);
            m = i;
        }
    }
    sum = fri.at(f) + mic.at(m);
    int sale = 0;
    for (int i = 0; i < M; i++) {
        if (off.at(i).at(0) - 1 == f && off.at(i).at(1) - 1 == m) {
            sale = max(sale, off.at(i).at(2));
        }
    }
    sum -= sale;
    ans = min(ans, sum);
    cout << ans << endl;
}