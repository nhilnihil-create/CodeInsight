# include <iostream>
# include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    while (n != 0) {
        int a[n] = {}; for (int i = 0; i < n; ++i) cin >> a[i];
        
        int min_diff = 1000000;
        for (int first = 0; first < n; ++first) {
            for (int second = first + 1; second < n; ++second) {
                int diff = abs(a[first] - a[second]);
                min_diff = min(min_diff, diff);
            }
        }
        cout << min_diff << endl;
        
        cin >> n;
    }
    return 0;
}
