#include "bits/stdc++.h"

using namespace std;

void Main() {
    string S;
    cin >> S;

    int ans = 0;
    int took = -1;
    string last = "";
    for (int i = 0; i < S.size(); ++i) {
        if (i == 0) {
            last = S.substr(0, 1);
            ++ans;
            took = 0;
            continue;
        }
        string sub = S.substr(took + 1, i - took);
        if (last == sub) {
            continue;
        }
        else {
            last = sub;
            ++ans;
            took = i;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
