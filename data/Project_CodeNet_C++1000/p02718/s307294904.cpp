#include<iostream>
using namespace std;

int main() {
    int n, m, a[110];

    cin >> n >> m;
    float sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int count = 0;
    float cond = sum / (4 * m);
    for (int i = 0; i < n; i++) {
        if (a[i] >= cond) count++;
    }

    if (count >= m) cout << "Yes" << endl;
    else cout << "No" << endl;

}