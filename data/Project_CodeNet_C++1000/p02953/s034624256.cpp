#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int h, prev=0, highest=0;
    for (int i=0; i<n; i++) {
        cin >> h;
        if (h < highest-1) {
            cout << "No" << endl;
            return 0;
        } else if (h > prev) {
            highest = h;
        }
        prev = h;
    }
    cout << "Yes" << endl;
}