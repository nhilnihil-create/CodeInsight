#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t A, B, M;
    cin >> A >> B >> M;
    vector<int64_t>reizou(A);
    vector<int64_t>renzi(B);
    for (int i=0; i<A; i++) {
        cin >> reizou.at(i);
    }

    for (int i=0; i<B; i++) {
        cin >> renzi.at(i);
    }

    int64_t min_cost = *min_element(reizou.begin(), reizou.end()) + *min_element(renzi.begin(), renzi.end());
    for (int i=0; i<M; i++) {
        int64_t x, y, c;
        cin >> x >> y >> c;
        int64_t cos = reizou[x-1] + renzi[y-1] - c;
        if (min_cost > cos) {
            min_cost = cos;
        }
    }

    cout << min_cost << endl;
    return 0;
}