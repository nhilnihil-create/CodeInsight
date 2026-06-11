#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

int main() {
    
    string s;
    cin >> s;
    map<string, int> m;
    m.emplace("MON", 6);
    m.emplace("TUE", 5);
    m.emplace("WED", 4);
    m.emplace("THU", 3);
    m.emplace("FRI", 2);
    m.emplace("SAT", 1);
    m.emplace("SUN", 7);
    
    cout << (m[s]);

    return 0;
}