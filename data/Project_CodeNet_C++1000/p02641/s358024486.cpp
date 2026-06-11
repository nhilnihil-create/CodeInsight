#include <iostream>

using namespace std;
int x, n;
bool exclude[102];

int main() {
    int a;
    cin >> x >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        exclude[a] = true;
    }

    int i = 0;
    while (true) {
        if (!exclude[x - i]) {
            cout << x - i << endl;
            return 0;
        }
        if (!exclude[x + i]) {
            cout << x + i << endl;
            return 0;
        }
        i++;
    }
}
