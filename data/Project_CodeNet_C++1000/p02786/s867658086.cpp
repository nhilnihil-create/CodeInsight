#include <bits/stdc++.h>
using namespace std;

// D - Caracal vs Monster
int main() {
    long long H;
    cin >> H;
    long long point = 2;
    while (point <= H) {
        point *= 2;
    }
    cout << point - 1;
}