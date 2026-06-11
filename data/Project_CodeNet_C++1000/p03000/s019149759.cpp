#include <iostream>
using namespace std;
int main() {
    int n, x;
    cin >> n >> x;
    int l[n], d[n+1];
    d[0] = 0;
    int cnt = 1;
    for (int i=0; i<n; i++) {
        cin >> l[i];
        d[i+1] = d[i] + l[i];
        if (d[i+1] <= x) {
            cnt++;
        } else {
            break;
        }
    }
    cout << cnt << endl;
}