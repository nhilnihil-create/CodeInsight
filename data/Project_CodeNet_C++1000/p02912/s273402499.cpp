#include <bits/stdc++.h>
using namespace std;

int main() {
    //
    int num, m;
    long long sum = 0;
    cin >> num >> m;

    priority_queue<long long> que;
    for (int i = 0; i < num; i++) {
        long long tmp;
        cin >> tmp;
        que.push(tmp);
    }

    for (int i = 0; i < m; i++) {
        long long tmp;
        tmp = que.top();
        que.pop();
        tmp /= 2;
        que.push(tmp);
    }

    while (!que.empty()) {
        sum += que.top();
        que.pop();
    }

    cout << sum << endl;
    //
}