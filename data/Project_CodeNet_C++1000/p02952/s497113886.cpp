#include <iostream>

int main() {
    using namespace std;
    int n, total;
    total = 0;
    cin >> n;
    int comp, cnt;
    for (int i=1; i<=n; i++) {
        comp = i;
        cnt = 0;
        while (comp != 0) {
            comp /= 10;
            cnt++;
            // cout << cnt << endl;
        }
        if (cnt & 1 == 1) total++;
    }
    cout << total;
}