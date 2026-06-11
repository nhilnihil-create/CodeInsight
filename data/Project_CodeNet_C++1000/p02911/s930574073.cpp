#include <iostream>
using namespace std;
int main() {
    int n, k, q;
    cin >> n >> k >> q;
    int pointUp[n];
    for (int i=0; i<n; i++) {
        pointUp[i] = 0;
    }
    for (int i=0; i<q; i++) {
        int a;
        cin >> a;
        pointUp[a-1]++;
    }
    for (int i=0; i<n; i++) {
        if (k-q+pointUp[i] > 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}