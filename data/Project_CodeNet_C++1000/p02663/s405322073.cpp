#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int H1, H2;
    int M1, M2;
    int K;
    int total = 0;
    cin >> H1 >> M1 >> H2 >> M2 >> K;
    if (M1 > M2) {
        M2 += 60;
        H2--;
    }
    total += M2 - M1;
    total += 60 * (H2-H1);
    cout << total - K << endl;
}
