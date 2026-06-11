#include <iostream>

using namespace std;

int main() {
    long long x, ans = 0;
    cin >> x;
    
    for(int a = 1; a < x; a++) {
        for(int b = 1; a*b < x; b++) {
            ans++;
        }
    }
    
    cout << ans << endl;

    return 0;
}
