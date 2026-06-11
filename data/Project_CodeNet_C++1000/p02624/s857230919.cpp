#include <iostream>
using namespace std;

long long n, ans;

int main() {
    cin >> n;
    for(long long k = 1; k <= n; k++) {
        long long i = n/k;
        ans += k*i*(i+1)/2;
    }
    cout << ans;
}
