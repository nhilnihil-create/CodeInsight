#include <bits/stdc++.h>
using namespace std;

int n,m;
long long tmp;
long long sum = 0;
priority_queue<long long> q;
int main() {

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        q.push(tmp);
    }
    for (int i = 0; i < m; ++i) {
        tmp = q.top();
        q.pop();
        q.push(tmp / 2);
    }
    for (int i = 0; i < n; ++i) {
        sum += q.top();
        q.pop();
    }
    cout << sum << "\n";
    return 0;
}
