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
    sort(fri.begin(), fri.end());
    sort(mic.begin(), mic.end());
    sum = fri.at(0) + mic.at(0);
    ans = min(ans, sum);
    cout << ans << endl;
}