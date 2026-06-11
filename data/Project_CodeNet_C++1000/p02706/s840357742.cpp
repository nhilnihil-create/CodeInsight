#include<bits/stdc++.h>
using namespace std;

int32_t main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    int N,M; cin >> N >> M;

    int sum = 0;
    for (int i = 1; i <= M; ++i) {
        int x; cin >> x;

        sum += x;
    }

    cout << (sum <= N ? N-sum : -1) << "\n";

}
