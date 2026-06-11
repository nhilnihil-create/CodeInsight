#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct robot {
    int left;
    int right;
};

bool struct_cmp(const struct robot& p, const struct robot& q) {
    return p.right < q.right;
}

int main() {
    int N;
    cin >> N;

    vector<robot> robots(N);
    for (int i = 0; i < N; i++) {
        int x, l;
        cin >> x >> l;
        robots[i].left = x - l;
        robots[i].right = x + l;
    }

    sort(robots.begin(), robots.end(), struct_cmp);

    int output = 0;
    int max = robots[0].left - 1;
    for (int i = 0; i < N; i++) {
        if (robots[i].left >= max) {
            output++;
            max = robots[i].right;
        }
    }
    cout << output << endl;

    return 0;
}
