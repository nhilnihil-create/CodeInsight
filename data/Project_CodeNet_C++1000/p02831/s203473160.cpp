#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a, long long b) {  
    return (a * b) / __gcd(a, b);  
} 

int main() {
    long long n, m; cin >> n >> m;
    cout << lcm(n, m) << "\n";
}