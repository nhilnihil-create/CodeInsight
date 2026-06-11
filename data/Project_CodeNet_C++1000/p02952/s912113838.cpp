#include <iostream>
#include <string>

int main() {
    using namespace std;
    int n, total;
    total = 0;
    cin >> n;
    for (int i=1; i<=n; i++) {
        // comp = i;
        // cnt = 0;
        // while (comp != 0) {
        //     // comp /= 10;
        //     // cnt++;
        //     // cout << cnt << endl;
        // }
        string x = to_string(i);
        if (x.size() % 2 == 1) total++;
    }
    cout << total;
}