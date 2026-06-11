#include <iostream>
#include <cmath>
using namespace std;
bool isSquare (int n) {
    for (int i=1; i*i<=n; i++) {
        if (i*i == n) {
            return true;
        }
    }
    return false;
}
int main() {
    int n, d;
    cin >> n >> d;
    int x[n][d];
    for (int i=0; i<n; i++) {
        for (int j=0; j<d; j++) {
            cin >> x[i][j];
        }
    }
    int cnt = 0;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            int sum = 0;
            for (int k=0; k<d; k++) {
                sum += pow((x[i][k]-x[j][k]), 2);
            }
            if (isSquare(sum)) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}