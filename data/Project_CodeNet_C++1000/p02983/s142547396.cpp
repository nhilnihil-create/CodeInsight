#include <iostream>
using namespace std;
int main() {
    int l, r;
    cin >> l >> r;
    if (r-l >= 2019) {
        cout << 0 << endl;
    } else {
        int result = 2018;
        for (int i=l; i<r; i++) {
            for (int j=i+1; j<=r; j++) {
                result = min(((i%2019)*(j%2019))%2019, result);
            }
        }
        cout << result << endl;
    }
}