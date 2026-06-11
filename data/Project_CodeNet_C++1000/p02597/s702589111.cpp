#include <iostream>

using namespace std;

int main() {
    int n;  cin >> n;
    char *c = new char[n];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    int i = 0, j = n-1;
    int ans = 0;
    while (i < j) {
        while (i < n && c[i] == 'R')
            i++;
        while (0 <= j && c[j] == 'W')
            j--;
        if (i < j) {
            ans++;
            c[i] = 'R';
            c[j] = 'W';
        }
    }

    cout << ans << endl;

    return 0;
}