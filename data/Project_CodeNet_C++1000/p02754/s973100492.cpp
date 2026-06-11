#include<iostream>
#include <vector>
using namespace std;

int main() {
    long long int n, a, b;
    cin >> n >> a >> b;
    long long int ans = 0;
    ans += (n / (a + b)) * a;
    if(n % (a + b) > a) {
        ans += a;
    }
    else {
        ans += n % (a + b);
    }
    cout << ans << "\n";
}