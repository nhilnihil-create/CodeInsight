#include "bits/stdc++.h"

using namespace std;

void dfs(int curr, int appeared, string prev, int N) {
    if (curr == N) {
        cout << prev << endl;
        return;
    }

    if (curr == 0) {
        dfs(curr + 1, appeared + 1, "a", N);
    }
    else {
        for (int i = 0; i < appeared; ++i) {
            char c = 'a' + i;
            dfs(curr + 1, appeared, prev + string({ c }), N);
        }
        char c = 'a' + appeared;
        dfs(curr + 1, appeared + 1, prev + string({ c }), N);
    }
}

void Main() {
    int N;
    cin >> N;
    dfs(0, 0, "", N);
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
