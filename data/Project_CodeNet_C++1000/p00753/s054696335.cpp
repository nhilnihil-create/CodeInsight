#include <iostream>

using namespace std;

bool is_prime(int n) {
    for(int i=2; i*i<=n; i++) if(n % i == 0) return false;
    return n != 1;
}

void solve(int n) {
    int ans = 0;
    for(int i=n+1; i<=2*n; i++) ans += is_prime(i);
    cout << ans << "\n";
}

int main() {
    int n;
    while(cin>>n && n) solve(n);
    return 0;
}