#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    unsigned long long a, b, m;
    cin >> a >> b >> m;
    vector<unsigned long long> refrigerators(a);
    vector<unsigned long long> microwaves(b);
    for (unsigned long long i = 0; i < a; ++i) cin >> refrigerators[i];
    for (unsigned long long i = 0; i < b; ++i) cin >> microwaves[i];
    unsigned long long min_price = *min_element(refrigerators.begin(), refrigerators.end()) + *min_element(microwaves.begin(), microwaves.end());
    for (unsigned long long i = 0; i < m; ++i) {
        unsigned long long x, y, c;
        cin >> x >> y >> c;
        unsigned long long price = refrigerators[x - 1] + microwaves[y - 1] - c;
        if (price < min_price) min_price = price;
    }
    cout << min_price << endl;
    return EXIT_SUCCESS;
}