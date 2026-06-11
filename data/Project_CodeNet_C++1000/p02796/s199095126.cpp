#include <bits/stdc++.h>
using namespace std;

int main() {
    int ans = 0;
    int N;
    cin >> N;
    vector<vector<int>> Robot(N, vector<int>(2));
    for(int i = 0; i < N; i++) {
        int X, L;
        cin >> X >> L;
        Robot.at(i).at(0) = X - L;
        Robot.at(i).at(1) = X + L;
    }
    sort(Robot.begin(), Robot.end(),
         [](const vector<int> &alpha, const vector<int> &beta) {
             return alpha[1] < beta[1];
         });
    int p = Robot.at(0).at(0);
    for(int i = 0; i < N; i++) {
        if(p <= Robot.at(i).at(0)) {
            ans++;
            p = Robot.at(i).at(1);
        }
    }

    cout << ans << endl;
}