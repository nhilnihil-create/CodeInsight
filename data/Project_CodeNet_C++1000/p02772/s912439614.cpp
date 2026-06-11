#include <iostream>

int main () {
    using namespace std;
    int n,s, a;
    cin >> n;
    s = 0;
    for (int i=0;i<n;i++) {
        cin >> a;
        // cout << ((int) a & 1);

        if ((a & 1) != 1) {
            // cout << a;
            if ((a % 3 != 0) && (a % 5 != 0)) {
                s = 1;
            }
        }
    }
    if (s==0) cout << "APPROVED";
    else cout << "DENIED";
}