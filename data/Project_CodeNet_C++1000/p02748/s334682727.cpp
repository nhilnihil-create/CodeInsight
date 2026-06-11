#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);
    for (int i = 0; i < A; i++) cin >> a.at(i); 
    for (int i = 0; i < B; i++) cin >> b.at(i);

    int minA = *min_element(a.begin(), a.end()); int minB = *min_element(b.begin(), b.end());
    int res = minA + minB;
    for (int i = 0; i < M; i++) {
        int x, y, c;
        cin >> x >> y >> c; x--; y--;
        res = min(res, a.at(x) + b.at(y) - c);
    }
    cout << res << endl;
}
