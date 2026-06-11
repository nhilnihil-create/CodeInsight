#include <iostream>

int main() {
    using namespace std;
    int a[9];
    for (int i=0; i<9; i++){
        cin >> a[i];
    }
    int n, b;
    cin >> n;
    for (int j=0; j<n; j++) {
        cin >> b;
        for (int i=0; i<9; i++){
            if (a[i] == b) {
                a[i] = -1;
            }
        }
    }
    if ((a[0]+a[1]+a[2]==-3) || (a[3]+a[4]+a[5]==-3) || (a[6]+a[7]+a[8]==-3) || 
        (a[0]+a[3]+a[6]==-3) || (a[1]+a[4]+a[7]==-3) || (a[2]+a[5]+a[8]==-3) ||
        (a[0]+a[4]+a[8]==-3) || (a[2]+a[4]+a[6]==-3)) {
            cout << "Yes";
        }
    else cout << "No";
}