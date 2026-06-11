#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L


int main() {
    
    int a, b;
    cin >> a >> b;
    a--;b--;
    vector<bool> f(3, true);
    f[a] = false;
    f[b] = false;
    for (int i = 0; i < 3; i++) {
        if (f[i]) cout << i + 1;
    }
    return 0;
}