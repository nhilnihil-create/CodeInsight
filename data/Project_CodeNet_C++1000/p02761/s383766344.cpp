#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> number(n, -1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        if (number[x] != -1 && number[x] != y) {
            cout << "-1";
            return 0;
        } 
        else if (number[x] == -1) {
            number[x] = y;
        }
    }
    if (number[0] == 0 && n != 1) {
        cout << "-1";
        return 0;
        //leading 0, if not 1 digit
    } else if (number[0] == -1 && n != 1) {
        number[0] = 1;
    }
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (number[i] == -1) {
            number[i] = 0;
        }
        k += pow(10, n - i - 1) * number[i];
    }
    cout << k;
}