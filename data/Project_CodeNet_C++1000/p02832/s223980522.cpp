#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        if (a == cnt+1) {
            cnt++;
        }
    }
    if (cnt == 0) {
        cout << -1 << endl;
    } else {
        cout << n-cnt << endl;
    }
}