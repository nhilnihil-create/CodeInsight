#include "bits/stdc++.h"

using namespace std;

void Main() {
    int N;
    cin >> N;
    double ansD = N / 1.08;
    int ans = (int)ansD;
    if ((int)(ans * 1.08) == N) {
        cout << ans << endl;
    }
    else if ((int)((ans + 1) * 1.08) == N) {
        cout << ans + 1 << endl;
    }
    else {
        cout << ":(" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
