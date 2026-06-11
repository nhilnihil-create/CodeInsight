#include "bits/stdc++.h"

using namespace std;

void Main() {
    int H, N;
    cin >> H >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        H -= a;
    }

    if (H <= 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
