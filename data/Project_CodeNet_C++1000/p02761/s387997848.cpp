#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n+1];   //左からi桁目をa[i]とする
    for (int i=1; i<n+1; i++) {
        a[i] = -1;
    }
    int s, c;
    for (int i=0; i<m; i++) {
        cin >> s >> c;
        if (s == 1 && c == 0 && n != 1) {
            cout << -1 << endl;
            return 0;
        } else if (a[s] == -1) {
            a[s] = c;
        } else if (a[s] != c) {
            cout << -1 << endl;
            return 0;
        }
    }
    int result = 0;
    for (int i=1; i<n+1; i++) {
        result *= 10;
        if (a[i] == -1) {
            if (i == 1 && n > 1) {
                a[i] = 1;
            } else {
                a[i] = 0;
            }
        }
        result += a[i];
    }
    cout << result << endl;
}