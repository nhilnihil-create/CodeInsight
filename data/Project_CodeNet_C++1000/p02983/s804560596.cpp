#include<iostream>
using namespace std;

int main() {
    int l, r;
    cin >> l >> r;

    int ml = l % 2019;
    int mr = r % 2019;

    int ans;
    if (r - l >= 2018) {
        cout << 0 << endl;
        return 0;
    } 

    if (mr <= ml) ans = 0;
    else { // ml < mr 
        ans = 2018;
        for (int i = ml; i < mr; i++) {
            for (int j = i+1; j <= mr; j++) {
                ans = min(ans, (i * j) % 2019);
            }
        }
    } 

    cout << ans << endl;
}