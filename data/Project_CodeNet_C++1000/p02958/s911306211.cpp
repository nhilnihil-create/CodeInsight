#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i=0; i<n; i++) {
        int p;
        cin >> p;
        if (p != i+1) {
            cnt++;
        }
    }
    if (cnt < 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}