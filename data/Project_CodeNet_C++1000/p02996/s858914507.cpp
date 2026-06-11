// 6/26 解き直し → 6/30
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const int INF = 1000000007;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    vector<P> task(N);
    // rep(i, N) task[i] = P(B[i] - A[i], A[i]);  // 締め切り。
    // sort(task.begin(), task.end());

    // int time = 0;
    // bool b = true;
    // rep(i, N) {
    //     if (time <= task[i].first) {
    //         time += task[i].second;
    //     } else {
    //         b = false;
    //         break;
    //     }

    //     printf("time, task, simekiri, A = %d, %d, %d, %d\n", time, i, task[i].first, task[i].second);
    // } 

    // if (b) cout << "Yes" << endl;
    // else cout << "No" << endl;

    rep(i, N) task[i] = P(B[i], A[i]);
    sort(task.begin(), task.end(), greater<P>());
    int time = task[0].first;  // 一番最後の締め切り
    rep(i, N) {
        if (task[i].first < time) time = task[i].first;
        time -= task[i].second;
    }
    if (time < 0) cout << "No" << endl;
    else cout << "Yes" << endl;
}