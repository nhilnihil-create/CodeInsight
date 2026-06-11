#include <iostream>

using namespace std;

int dfs(int n, int s, int minimum) {
    if (n == 0 && s == 0) {
        return 1;
    }
    if (n <= 0 && s <= 0) {
        return 0;
    }
    int ret = 0;
    for (int i = minimum; i < 10; ++i) {
        ret += dfs(n - 1, s - i, i + 1);
    }
    return ret;
}

int main() {
    while (true) {
        int n, s;
        cin >> n >> s;
        if (n == 0 && s == 0) {
            return 0;
        }
        cout << dfs(n, s, 0) << endl;
    }
}