#include <iostream>
#include <cmath>
using namespace std;

long long n;
int ans;

int main() {
    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    long long x = sqrt(n);
    for(long long i = 2; i < x; i++) {
        int e = 0;
        long long pow = i;
        while(n%pow == 0) {
            e++;
            n /= pow;
            pow *= i;
        }
        while(n%i == 0) n /= i;
        ans += e;

        if(n == 1) {
            cout << ans;
            return 0;
        }
    }
    ans++;
    cout << ans;
}
