#include <iostream>

#define int long long

using namespace std;


signed main() {
    int n, m;
    cin >> n >> m;

    int counter = 0;
    int l = 1, r = m + 1;
    while (l < r) {
        cout << l << " " << r << endl;
        l++;
        r--;
        counter++;
    }

    l = m + 2, r = 2 * m + 1;
    while (l < r) {
        cout << l << " " << r << endl;
        l++;
        r--;
    }
    
    return 0;
}