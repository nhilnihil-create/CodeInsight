#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, M;
    cin >> A >> B >> M;

    vector<int> a(A), b(B);
    int min_a = INT_MAX, min_b = INT_MAX;
    for (int i = 0; i < A; i++) {
        cin >> a.at(i);
        min_a = min(min_a, a.at(i));
    }
    for (int i = 0; i < B; i++) {
        cin >> b.at(i);
        min_b = min(min_b, b.at(i));
    }

    int min_cost = min_a + min_b;
    for (int i = 0; i < M; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        min_cost = min(min_cost, a.at(x) + b.at(y) - c);
    }

    cout << min_cost << endl;
}