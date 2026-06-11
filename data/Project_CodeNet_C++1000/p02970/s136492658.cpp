#include <iostream>
using namespace std;

int main() {
    int n,d;
    cin >> n >> d;
    int ans = 0;
    int sum = 0;

    for (int i = 0; sum < n; i++) {
        sum += 2 * d + 1;
        ans++;
    } 

    cout << ans << endl;
}