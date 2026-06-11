#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int64_t total = 1;
    bool zero = 0;

    vector<int64_t> vec(100010);
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
        if (vec.at(i) == 0) {
            zero = 1;
        }
    }

    if (zero) {
        cout << 0 << endl;
        return 0;
    }
    
    for (int i = 0; i < n; i++) {
        if (total <= 1000000000000000000 / vec.at(i)) {
            total *= vec.at(i);
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << total << endl;
}